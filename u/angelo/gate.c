#include <ansi.h>
  inherit ROOM;
void init();
int valid_leave();
void create()
{
        set("short", HIG"�ۺ�С��"NOR);
        set("long", @LONG
ֻ�������Ϲ���һ�����������ķ���,����һҡ�ᷢ���ͳ��İ����������
��������϶���һ�����������������ÿ���д���ĸ���--�ۺ�С��,͸�������
����ȥֻ��һ��Ƭ��������ĺɻ�Χ��������ˮ������¥��
LONG);
        set("exits", ([
                "enter" : "/u/angelo/livingroom",
                "east" : "/d//hangzhou/louwlou",
                "down" : "/d//yangzhou/kedian",
                      "west" : "/u/fanren/workroom", 
               "hist" : "u/angelo/histroom",
]));
setup(); 
   call_other("/clone/board/angelo_b", "???");  
  
}
