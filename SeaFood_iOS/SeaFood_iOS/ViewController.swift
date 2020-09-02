//
//  ViewController.swift
//  SeaFood_iOS
//
//  Created by 김수완 on 2020/09/02.
//  Copyright © 2020 김수완. All rights reserved.
//

import UIKit
import WebKit
import SideMenu

class ViewController: UIViewController, WKUIDelegate, WKNavigationDelegate {
    
    var menu: SideMenuNavigationController?

    @IBOutlet weak var webViewer: WKWebView!
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
        loadUrl("https://www.nike.com")
        
        menu = SideMenuNavigationController(rootViewController: MenuListController())
        menu?.leftSide = true
        
        SideMenuManager.default.leftMenuNavigationController = menu
        SideMenuManager.default.addPanGestureToPresent(toView: self.view)
    }
    
    func loadUrl(_ url : String){
        let request = URLRequest(url: URL(string: url)!)
        
        webViewer.load(request)
        
        webViewer.uiDelegate = self
        webViewer.navigationDelegate = self
    }
    
    @IBAction func didTapMenu() {
        present(menu!, animated: true)
    }
}


