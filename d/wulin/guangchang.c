// room /d/wulin/shangshan.c
//updated by Lara 2001/10/17
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "Ӣ�۴��㳡");
        set("long", @LONG
�˴�����Ӣ�۴��㳡�ˡ�ÿ�����������ش�����鷢�����������������
���ٿ�Ӣ�۴�ᣬ��ȶ���£������и�·���ֶ����Ƽ��ڴˣ��������Ǻ����
�㳡��ǰ��������̨��̨�������һ���ƽ�����������Ƕ�Ÿ���ɫ��ѣĿ�ı�
ʯ���ڱ����ĺ�������һ��ֱ������Ĵ��죬���ϡ������е����ĸ�����������
�������������⡣
LONG
        ); 
                set("exits", ([
                  "west" : __DIR__"shangwu",
                  ]));
                set("objects",([
                __DIR__"npc/yishi" : 2,
        ]));

                set("cost", 1);
                setup();
         call_other("/clone/board/hero_b", "???");

}



