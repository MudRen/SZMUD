// Code of ShenZhou
// hd_zoulang.c �������
// xQin 11/00

inherit ROOM;
#include <room.h>

void create()
{
	set("short", "�������" );
	set("long", @LONG
����������������ȣ�����������ϡ�١���������һ���ߵ����ﶼ
��ֹ�������ȶ�����ͷ��ͬ����ҩ���ȵأ�������Ǻ�Ժ��
LONG
	);
	set("exits", ([
		"south" : __DIR__"houyuan",
		"north" : __DIR__"sanqingdian",
		"east" : __DIR__"donglang1",
		"west" : __DIR__"xilang1",
	]));

	set("objects", ([
		"/kungfu/class/wudang/xi.c" : 1,
	]));
		
	setup();

}
int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam = (mapping)me->query("family");

        if ((!myfam || myfam["family_name"] != "�䵱��") 
        && objectp(present("zhang songxi", environment(me))) ) {
        	
        if (dir == "east" || dir == "west" || dir == "south") 
           return notify_fail("����Ϫ�ȵ����������䵱�صأ�������ֹ����\n");
        }        
        return ::valid_leave(me, dir);
}
