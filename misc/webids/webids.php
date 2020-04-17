
<?php

$datadirectory = realpath('/var/www/misc/webids/');
$path = realpath('/var/www/');

$objects = new RecursiveIteratorIterator(new RecursiveDirectoryIterator($path) );
	#TODO: if number of files are larger than xx, do not calculate hashes. tell user that list is too large, use variable like $maxnumberoffiles
foreach($objects as $name => $object){

	#Do not include the webids data directory
	if (strpos($name,$datadirectory) === false){

		#TODO: if file size is larger than xx, do not calculate hash. collect in list, and tell user than these following files are larger than xx. Use variable like maxfilesize
		$hash = hash_file(sha256, $name, false);

		#Put the filename and hash value to an array
		$array[$name] = $hash ;
	}
}

$currenttime= date("Y-m-d_H:i:s");
$datadir='data/';

#Create a new file with the new data:
$newfilename = $datadir.$currenttime.'_hashes.txt';
$serializedarray = serialize($array);
file_put_contents($newfilename,$serializedarray);

#Read the latest old file with the latest old data:
$latestfilename=$datadir.'latest_hashes.txt';
$storedserializedarray=file_get_contents($latestfilename);
$storedarray=unserialize($storedserializedarray);

#Create a new latest file
copy($newfilename,$latestfilename);

$diffchanges = array_diff($array,$storedarray);
$diffdeleted = array_diff_key($storedarray,$array);
$diffadded = array_diff_key($array,$storedarray);

#Build a report for emailing
$report = "Report on file changes within server xx\r\n";
$report .= 'Timestamp: '.$currenttime."\r\n";
if (!empty($diffchanges)){
	$report .= "Changed files: ";
	$report .= print_r($diffchanges,true);
} else {
	$report .= "No changed files since last.\r\n";
}
if (!empty($diffdeleted)){
	$report .= "Deleted files: ";
	$report .= print_r($diffdeleted,true);
} else {
	$report .= "No deleted files since last.\r\n";
}
if (!empty($diffadded)){
	$report .= "Added files: ";
	$report .= print_r($diffadded,true);
} else {
	$report .= "No new files since last.\r\n";
}

$emailaddress = "lasg@lasg.dk";
echo ("The following report is being emailed:\r\n".$report);
mail($emailaddress,'Report from WEBIDS on server xx',$report);

?>
