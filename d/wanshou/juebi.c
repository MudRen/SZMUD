// Code of ShenZhou
// /d/wanshou/juebi.c
// snowbird July 1999
// 1.1.1.1

#include "room.h"

inherit ROOM;

void create()
{
        set("short", "ׯ�����");
        set("long", @LONG
��������ɽׯ�����Σ�£�����Ħ�죬����ס��±�һ��ǧ
������бб���Ծ�����̽��ͷȥ���������ۣ�����ν����������
�˳����������߹�״�¡���
LONG
        );
        set("exits", ([
				"south" : __DIR__"shulin",
        ]));

        set("outdoors", "wanshou-shanzhuang");

	    set("cost", 1);
        setup();
        replace_program(ROOM);

}
