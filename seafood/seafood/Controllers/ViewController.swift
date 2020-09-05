//
//  ViewController.swift
//  seafood
//
//  Created by 김수완 on 2020/09/03.
//  Copyright © 2020 김수완. All rights reserved.
//

import UIKit

class ViewController: UIViewController {
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        self.navigationController?.navigationBar.topItem?.title = "SEAFOOD"
        // Do any additional setup after loading the view.
        sideMenu()
    }
    
    @IBOutlet var menuButton: UIBarButtonItem!
    func sideMenu(){
        if let revealVC = self.revealViewController() {
            self.menuButton.target = revealVC
            self.menuButton.action = #selector(revealVC.revealToggle(_:))
            self.view.addGestureRecognizer(revealVC.panGestureRecognizer())
        }
    }
    @IBAction func goMyPageBtn(_ sender: Any) {
        let vcName = self.storyboard?.instantiateViewController(withIdentifier: "myPageVC")
        vcName?.modalPresentationStyle = .fullScreen
        vcName?.modalTransitionStyle = .coverVertical
        self.present(vcName!, animated: true, completion: nil)
    }
    
    @IBAction func goMyCartBtn(_ sender: Any) {
        let vcName = self.storyboard?.instantiateViewController(withIdentifier: "myCartVC")
        vcName?.modalPresentationStyle = .fullScreen
        vcName?.modalTransitionStyle = .coverVertical
        self.present(vcName!, animated: true, completion: nil)
    }
}

