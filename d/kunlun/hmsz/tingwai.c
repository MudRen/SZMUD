// tingwai.c (kunlun)

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
                  set("short", "����");
                  set("long",@long
    ���˺�һ�ᣬ����һ������֮�⣬ֻ�����ϱ��д�š�����Ӫ�����֡�
��������ԼԼ������Ů�ĺǳ���.  
long);
                 set("exits",([
"west" : __DIR__"luange",
"enter" : __DIR__"laoying",
]));

              setup();
              replace_program(ROOM);
}
