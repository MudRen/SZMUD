//Cracked by Roath
// /d/shenlong/tanggu.c
// ALN Sep / 97

#include <ansi.h>

inherit HARBOR;

void create()
{
        set("short", "������");
        set("long", @LONG
������Ǵ�֮�����˻��Ĵ��Ž�ʯ����������������������һȺȺ��
Ÿ��ŷŷ..���ؽ��ţ���ʱ�����Ծ�����棬��������˻����������Ҵ�
��(chuan)���������ż����������ˣ��˴��ɶɹ��󺣵��ﺣ����һ�ˡ�
���������ǣ�������һ���޼ʵĴ󺣡�
LONG
        );

        set("outdoors", "shenlong");
        set("exits", ([
                "northwest" : __DIR__"dadao_yongan_s",
        ]));

        set("item_desc", ([
                "chuan" : "����һ�Һ����������˶ɺ������Ǵ�����ƽʱҲ���������㡣\n",
        ]));

        set("objects", ([
      //    "/d/shenlong/npc/yufu1" : 1,
            "/clone/obj/car" : 1,
        ]));

        set("navigate/locx", 0);
        set("navigate/locy", 0);

        set("cost", 2);

        setup();
}
