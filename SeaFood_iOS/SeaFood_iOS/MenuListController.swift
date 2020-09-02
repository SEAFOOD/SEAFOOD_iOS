//
//  MenuListController.swift
//  SeaFood_iOS
//
//  Created by 김수완 on 2020/09/02.
//  Copyright © 2020 김수완. All rights reserved.
//

import UIKit

class MenuListController: UITableViewController {
    
    var items = [item]()
    
    override func viewDidLoad() {
        super.viewDidLoad()
        configureItems()
        tableView.register(UITableViewCell.self, forCellReuseIdentifier: "cell")
    }
    
    func configureItems(){
        items.append(item(title: "마이페이지",
                          identifier: "myPage",
                          className: "myPageViewController",
                          cellSize: 150))
    }
    
    override func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        print("tlqkf")
    }
    
    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return items.count
    }
    
    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: "cell", for: indexPath)
        cell.textLabel?.text = items[indexPath.row].title
        return cell
    }
    
    override func tableView(_ tableView: UITableView, heightForRowAt indexPath: IndexPath) -> CGFloat {
        return CGFloat(items[indexPath.row].cellSize)
    }
}

struct item {
    let title: String
    let identifier: String
    let className: String
    let cellSize: Int
}
