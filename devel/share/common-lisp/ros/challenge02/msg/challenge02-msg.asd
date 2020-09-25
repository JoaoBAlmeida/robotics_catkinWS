
(cl:in-package :asdf)

(defsystem "challenge02-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "Pos" :depends-on ("_package_Pos"))
    (:file "_package_Pos" :depends-on ("_package"))
  ))