#!/bin/sh

sort queue_req.txt|uniq > queue_req.tmp &&
mv queue_req.tmp queue_req.txt

sort queue_run.txt|uniq > queue_run.tmp &&
mv queue_run.tmp queue_run.txt

