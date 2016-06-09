#!/usr/bin/env node

"use strict";

/* jshint strict: true */
/* jshint node: true */
/* jshint unused: false */

var fs = require('fs');

var mergeSort = function(arr, low, mid, high) {
    var i = low;
    var m = mid + 1;
    var l = low;

    var temp = [];
    var k;

    while ((l <= mid) && (m <= high)) {

        if (arr[l] <= arr[m]) {
            temp[i] = arr[l];
            l++;
        } else {
            temp[i] = arr[m];
            m++;
        }
        i++;
    }

    if (l > mid) {
        for (k = m; k <= high; k++) {
            temp[i] = arr[k];
            i++;
        }
    } else {
        for (k = l; k <= mid; k++) {
            temp[i] = arr[k];
            i++;
        }
    }

    for (k = low; k <= high; k++) {
        arr[k] = temp[k];
    }
};

var partition = function(arr, low, high) {
    var mid;
    if (low < high) {
        mid = Math.floor((low + high) / 2);
        partition(arr, low, mid);
        partition(arr, mid + 1, high);
        mergeSort(arr, low, mid, high);
    }
};

var filename = "../TestData.txt";

fs.readFile(filename, 'utf8', (err, data) => {
    if (err) throw err;

    var nums = data.split("\n");
    var arr = [];
    nums.forEach(function(numLine) {
        if (numLine.trim().length !== 0) {
            arr.push(parseInt(numLine));
        }
    });

    var start = process.hrtime();
    partition(arr, 0, arr.length - 1);
    var diff = process.hrtime(start);
    var secs = (diff[0] * 1e9 + diff[1]) / 1e9;
    secs = secs.toPrecision(3);

    arr.forEach(function(n){
        console.log(n);
    });

    console.log(`time: ${secs} (secs)`);

});
