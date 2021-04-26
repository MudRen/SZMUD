// Code of ShenZhou
// Room: /d/dali/garden7.c

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", HIG"�軨Ժ"NOR);
	set("long", @LONG
�������ر��ǲ軨��������ɫ��Ѥ�����ˡ�������ʱʱ��
�۷������䡣��ʯ·��ȴ����һ����Ʒ���ֲ軨(flower)��
LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
  "flower" : HIG"����
���£���һ����׻���΢�������ĺڰߵģ���׻�����һ��
���£���Щ�ڰߣ��������еĹ�֦�ˡ�
"NOR,
]));
	set("cost", 1);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"garden6",
]));

//        set("objects", ([
  //              __DIR__"npc/huajiang": 1,
    //

    
// ]));                                                                  
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
