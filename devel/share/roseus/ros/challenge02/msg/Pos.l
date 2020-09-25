;; Auto-generated. Do not edit!


(when (boundp 'challenge02::Pos)
  (if (not (find-package "CHALLENGE02"))
    (make-package "CHALLENGE02"))
  (shadow 'Pos (find-package "CHALLENGE02")))
(unless (find-package "CHALLENGE02::POS")
  (make-package "CHALLENGE02::POS"))

(in-package "ROS")
;;//! \htmlinclude Pos.msg.html


(defclass challenge02::Pos
  :super ros::object
  :slots (_X ))

(defmethod challenge02::Pos
  (:init
   (&key
    ((:X __X) 0)
    )
   (send-super :init)
   (setq _X (round __X))
   self)
  (:X
   (&optional __X)
   (if __X (setq _X __X)) _X)
  (:serialization-length
   ()
   (+
    ;; int64 _X
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int64 _X
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _X (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _X) (= (length (_X . bv)) 2)) ;; bignum
              (write-long (ash (elt (_X . bv) 0) 0) s)
              (write-long (ash (elt (_X . bv) 1) -1) s))
             ((and (class _X) (= (length (_X . bv)) 1)) ;; big1
              (write-long (elt (_X . bv) 0) s)
              (write-long (if (>= _X 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _X s)(write-long (if (>= _X 0) 0 #xffffffff) s)))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int64 _X
#+(or :alpha :irix6 :x86_64)
      (setf _X (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _X (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;;
   self)
  )

(setf (get challenge02::Pos :md5sum-) "1e404dd3cb6d4bfb308931d7bf3cfb43")
(setf (get challenge02::Pos :datatype-) "challenge02/Pos")
(setf (get challenge02::Pos :definition-)
      "int64 X

")



(provide :challenge02/Pos "1e404dd3cb6d4bfb308931d7bf3cfb43")


