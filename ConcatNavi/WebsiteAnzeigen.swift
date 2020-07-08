//
//  WebsiteAnzeigen.swift
//  ConcatNavi
//
//  Created by Benutzer on 05.05.20.
//  Copyright © 2020 Benutzer. All rights reserved.
//

import Foundation
import UIKit
import WebKit

class WebsiteAnzeigen: UIViewController, WKNavigationDelegate {
    
    @IBOutlet var webView: WKWebView!
    
    @IBOutlet var spinner: UIActivityIndicatorView!
    
    
    override func viewDidLoad() {
    super.viewDidLoad()
        
    let url = URL(string: "https://www.concat.de")
    let request = URLRequest(url: url!);
    
    webView.load(request);
    
    webView.addSubview(spinner)
    spinner.startAnimating();
    
    
    webView.navigationDelegate = self;
    spinner.hidesWhenStopped = true;
    
  
    }
    
    
    func webView(_ webView: WKWebView, didFinish navigation: WKNavigation!) {
        
        spinner.stopAnimating();
        
    }
    
    
    func webView(_ webView: WKWebView, didFail navigation: WKNavigation!, withError error: Error) {
        
        spinner.stopAnimating();
        
    }
    
    
}
