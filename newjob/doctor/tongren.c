//blacko

inherit ROOM;

void create()
{
        set("short","同仁堂乐家老号");

        set("long",@LONG
这里是全国著名的同仁堂老号，他位于北京住前门外大栅栏。同仁堂之名
是由取「同修仁德，济世养生」之意。此店面以有三百年的历史由乐家历代经
营和管理。这店面看上去有些陈旧大概是由于两次大火的缘故烧了部份的陈设
和外观，从外面看进去可以看到一个老头在招呼客人。
LONG);

        set("exits",([ "enter" : __DIR__"/newjob/doctor/tongren",
                  
                      ])
           );
          set("cost",1);

          set("objects",([
                "/newjob/doctor/npc/xianyang" : 1,
          ]));


        setup();

}