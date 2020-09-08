//
//  InfoViewController.swift
//  seafood
//
//  Created by 김수완 on 2020/09/05.
//  Copyright © 2020 김수완. All rights reserved.
//

import UIKit
import WebKit

class InfoViewController: UIViewController, WKUIDelegate, WKNavigationDelegate {

    @IBOutlet var InfoWV: WKWebView!
    
    override func viewDidLoad() {
        super.viewDidLoad()

        loadUrl("https://www.nike.com/kr/ko_kr/")
    }

    
    func loadUrl(_ url : String){
        let request = URLRequest(url: URL(string: url)!)
        
        InfoWV.load(request)
        
        InfoWV.uiDelegate = self
        InfoWV.navigationDelegate = self
    }
}d
