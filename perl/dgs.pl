#!/usr/bin/perl

package DeGuleSider;

use HTTP::Request::Common;
use LWP::UserAgent;
use strict;
use warnings;
use diagnostics;

sub new {
    my $class = shift;

    my %this = ();

    return bless \%this, $class;
}

sub handle {
    my ($self, $client, %input) = @_;

    my $callerid = $input{"callerid"};
    if ($callerid=~/<(\d+)\>/) {
        ($callerid) = $callerid =~/\<(\d+)\>/;
    } else {
        $callerid=$callerid;
    }

    my $res = LWP::UserAgent->new()->
      request(GET
'http://www.degulesider.dk/vbw/super/resultat.do?compPhone='.$callerid);

    my $gotit = $res->is_success;
    my ($name) = $res->content =~ /<td class="navn" align="left"
valign="middle">(.*?)<\/td>/s;

    $name=~s/[^a-zA-Z ]/x/g;
    $name=uc(substr($name,0,15));
    print "NAME=$name CALLERID: $callerid\n";
    ast_cmd($client, "EXEC SetCIDName \"$name\"");
    #close($client);
}

sub ast_cmd {
  my ($socket, $cmd) = @_;

  my $res=0;
  if ($socket->connected) {
    print STDERR "SENDER $cmd til socket\n";
    print $socket "$cmd\n";
    my $result = <$socket>;
    &checkresult($result);
    $res=1;
  }
  return $res;
}

sub checkresult {
        my ($res) = @_;
        my $retval;
        my $tests++;
        my $fail;
        my $pass;

        chomp $res;
        if ($res =~ /^200/) {
                $retval = $res =~ /result=(-?\d+)/;
                if (!length($1)) {
                        print STDERR "FAIL ($res)\n";
                        $fail++;
                } else {
                        print STDERR "PASS ($1)\n";
                        $pass++;
                }
        } else {
                print STDERR "FAIL (unexpected result '$res')\n";
                $fail++;
        }
        return $retval;
}

{1;}




