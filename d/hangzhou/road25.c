// Code of ShenZhou
// ��ʯ���
// Dong  11/03/1996.
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{   set("short", "��ʯ���");
    set("long", @LONG
�غ�����Ե������������ֹ��ӣ������۴��αȣ���������������
һƬ̫ƽ���־���������һ��԰�����˽���������ʮ�����֡�����
����ҽ�����࿪��ҩ�̡�
LONG);

    set("exits", ([ /* sizeof() == 4 */ 
                   "northeast" : __DIR__"road24", 
                   "southwest" : __DIR__"road71", 
                   "west" : __DIR__"jujing1", 
                   "east" : __DIR__"yaodian", 
                 ])
       );
	set("cost", 1);
        set("outdoors", "hangzhou");
    setup();
    replace_program(ROOM);
}