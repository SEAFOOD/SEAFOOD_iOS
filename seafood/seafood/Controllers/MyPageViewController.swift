//
//  MyPageViewController.swift
//  seafood
//
//  Created by 김수완 on 2020/09/04.
//  Copyright © 2020 김수완. All rights reserved.
//

import UIKit

class MyPageViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        self.navigationController?.navigationBar.tintColor = UIColor.darkGray
        self.navigationController?.navigationBar.topItem?.title = ""
    }

    @IBAction func backButton(_ sender: Any) {
        self.presentingViewController?.dismiss(animated: true)
    }
    
}
