//
//  HomeView.swift
//  ConcatNavi
//
//  Created by Benutzer on 30.04.20.
//  Copyright © 2020 Benutzer. All rights reserved.
//

import Foundation
import UIKit

import UserNotifications

class HomeView: UIViewController {
    
    
    @IBOutlet var buttonMap: UIButton!
    @IBOutlet var buttonWebsite: UIButton!
    
    
    func registerForPushNotifications() {
        UNUserNotificationCenter.current()
        .requestAuthorization(options: [.alert, .sound, .badge]) {(granted, error) in
        print("Permission granted: \(granted)")
        }
    }
    

    
    override func viewDidLoad() {
    super.viewDidLoad()
        
        self.buttonMap.layer.cornerRadius = 20
        self.buttonWebsite.layer.cornerRadius = 20
    
        registerForPushNotifications()
    }
}
