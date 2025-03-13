//
//  ContentView.swift
//  testMemo
//
//  Created by Yugo Okugawa on 2025/02/16.
//

//import SwiftUI
//
//struct ContentView: View {
//    var body: some View {
//        VStack {
//            Image(systemName: "globe")
//                .imageScale(.large)
//                .foregroundStyle(.tint)
//            Text("Hello, world!")
//        }
//        .padding()
//    }
//}
//
//#Preview {
//    ContentView()
//}


import SwiftUI
import RealmSwift

struct ContentView: View {
    var body: some View {
        VStack {
            Text("Realm Test")
                .onAppear {
                    do {
                        let realm = try Realm()
                        print("Realm file location:", realm.configuration.fileURL ?? "No file URL")
                    } catch {
                        print("Realm error:", error)
                    }
                }
        }
    }
}
