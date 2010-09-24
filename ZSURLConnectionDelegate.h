/*
 * ZSURLConnectionDelegate.h
 *
 * Created by Marcus S. Zarra
 * Copyright Zarra Studos LLC 2010. All rights reserved.
 *
 * Implementation of an image cache that stores downloaded images
 * based on a URL key.  The cache is not persistent (OS makes no
 * guarantees) and is not backed-up when the device is sync'd.
 *
 *  Permission is hereby granted, free of charge, to any person
 *  obtaining a copy of this software and associated documentation
 *  files (the "Software"), to deal in the Software without
 *  restriction, including without limitation the rights to use,
 *  copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the
 *  Software is furnished to do so, subject to the following
 *  conditions:
 *
 *  The above copyright notice and this permission notice shall be
 *  included in all copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 *  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 *  OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 *  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 *  HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 *  WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 *  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 *  OTHER DEALINGS IN THE SOFTWARE.
 *
 */

@class ZSURLConnectionDelegate;

@interface ZSURLConnectionDelegate : NSOperation 
{
  BOOL executing;
  BOOL finished;
  
  id object;
  id delegate;
  
  NSUInteger retryCount;
  NSURL *myURL;
  NSMutableData *data;
  NSURLConnection *connection;
  NSHTTPURLResponse *response;
  BOOL thumbnail;
  
  SEL successSelector;
  SEL failureSelector;
  SEL parseSelector;
}

@property (nonatomic, readonly) BOOL isExecuting;
@property (nonatomic, readonly) BOOL isFinished;

@property (nonatomic, retain) id object;
@property (nonatomic, retain) NSURL *myURL;
@property (nonatomic, retain) NSHTTPURLResponse *response;
@property (nonatomic, retain) id delegate;

@property (nonatomic, assign) SEL parseSelector;
@property (nonatomic, assign) SEL successSelector;
@property (nonatomic, assign) SEL failureSelector;
@property (nonatomic, assign) NSURLConnection *connection;
@property (nonatomic, assign, getter=isThumbnail) BOOL thumbnail;
@property (nonatomic, assign) NSUInteger retryCount;

@property (nonatomic, readonly) NSData *data;

- (id)initWithURL:(NSURL*)aURL delegate:(id)delegate;

@end
