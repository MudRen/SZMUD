// Code of ShenZhou
// Jay 7/11/96

#include "tree.h"

void create()
{
    int i;
        set("short", "����");
        set("long", @LONG
��������߰�����ֻ������ͷ���ϴ���һЩ�����������ż����
ï�ܵ�Ҷ��͸����һ�߹������Ҷ�ڷ��衣��ľ���õ���ζ�����ᴫ
��Ұ�޵�Х��ʹ�˲�����ԥ��ǰ���ĽŲ�������һ�����(river)
�������졣
LONG
        );

/*        set("objects", ([
            "/d/city/obj/branch" : 1,
	    "/d/quanzhou/npc/wuya" : 1,
	]));
 */
        set("exits", ([
                "west" : __DIR__"gate",
        ]));

	set("climbup",__DIR__"tree17");
	set("item_desc", ([
		"river" : "�����ļ����ɴ��ѹ������������������������֦�������\n",
	]));

	set("cost", 3);
        setup();
}

