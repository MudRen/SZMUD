// Code of ShenZhou
// /d/wanshou/frontgate.c
// snowbird July 1999
// 1.1.1.1

#include "room.h"

inherit ROOM;

void create()
{
        set("short", "����ɽׯ");
        set("long", @LONG
ǰ���������ɽׯ�ˣ�ɽׯ�����ϵ���Ż���ʨ����ͼ�ڣ�
��������һ��ͺڵ׽��ֵ��Ҷ���顰����ɽׯ���ĸ��Ծ���
���Ĵ��֡���ǰһ��һ�Ҹ���һֻ�ͻ�����Ŀ��ת���ض������
һ��һ����
LONG
        );
        set("exits", ([
				"north" : __DIR__"qianting",
				"south" : __DIR__"shijie",
        ]));

        set("outdoors", "wanshou-shanzhuang");

	    set("cost", 1);
        setup();
        replace_program(ROOM);

}
