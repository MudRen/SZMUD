// Code of ShenZhou
// /d/shenlong/beach.c
// by ALN Sep / 97

#include <ansi.h>

inherit HARBOR;

void create()
{
        set("short", "����");
        set("long", @LONG
�����������ĳ����ڣ��˻��Ĵ��Ž�ʯ����������������������һȺȺ��
Ÿ��ŷŷ..���ؽ��ţ���ʱ�����Ծ�����棬��������˻����������Ҵ�
(chuan)�� �������ż�����������ˣ��˴��ɶɹ��󺣵��ﺣ����һ�ˡ���
�����������ĺ�̲��
LONG
        );

        set("outdoors", "shenlong");

        set("exits", ([
                "east" : __DIR__"haitan",
        ]));

        set("item_desc", ([
                "chuan" : "����һ�Һ����������˶ɺ������Ǵ�����ƽʱҲ���������㡣\n",
        ]));

        set("objects", ([
    //             "kungfu/class/shenlong/bailong" : 1,
    //             "/d/shenlong/npc/bai" : 1,
        ]));

        set("island", "������");
        set("shape", "����һƬ½�ء�");
        set("navigate/locx", 30);
        set("navigate/locy", 20);

        set("cost", 3);

        setup();
}
