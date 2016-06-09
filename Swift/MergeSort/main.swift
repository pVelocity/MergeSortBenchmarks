//
//  main.swift
//  MergeSort
//
//  Created by Kang Lu on 2016-06-07.
//  Copyright © 2016 Kang Lu. All rights reserved.
//

import Foundation

let BUFFER_SIZE = 1024
let INT_SIZE = 10000

let filename = "../../../../../../TestData.txt"

let text = try String(contentsOfFile: filename, encoding: NSUTF8StringEncoding)
var lines:[String] = text.componentsSeparatedByString("\n")

lines.popLast()

var nums = [Int?](count:INT_SIZE, repeatedValue:nil)
var temp = [Int?](count:INT_SIZE, repeatedValue:nil)

for (index, value) in lines.enumerate() {
    nums[index] = Int.init(value)!
}

func mergeSort(inout arr: [Int?], low:Int, mid: Int, high:Int) -> Void {
    var i = low
    var l = low
    var m = mid + 1
    var k: Int
    
    while((l <= mid) && (m <= high)){
        
        if(arr[l] >= arr[m]){
            temp[i] = arr[l];
            l += 1;
        }
        else{
            temp[i] = arr[m];
            m += 1;
        }
        i += 1;
    }
    
    if(l > mid){
        k = m
        while (k <= high) {
            temp[i] = arr[k]
            i += 1
            k += 1
        }
    }
    else{
        k = l
        while (k <= mid) {
            temp[i] = arr[k]
            i += 1
            k += 1
        }
    }
    
    k = low
    while (k <= high) {
        arr[k] = temp[k]!
        k += 1
    }
}

func partition(inout arr: [Int?], low:Int, high:Int) -> Void {
    if(low<high){
        let mid=(low+high)/2;
        partition(&arr, low: low, high: mid);
        partition(&arr, low: mid+1, high: high);
        mergeSort(&arr, low: low, mid: mid, high: high);
    }
}

let start = NSDate().timeIntervalSince1970;
partition(&nums, low: 0, high: nums.count - 1)
let end = NSDate().timeIntervalSince1970;

for var i in nums.reverse() {
    print(i!)
}

let et = NSString(format: "%.6f", (end - start));

print("Elapsed time: \(et) (secs)");
