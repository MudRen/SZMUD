// Code of ShenZhou
// modified by aln 4 / 98

#include <ansi.h>

inherit HARBOR;

void create()
{
        set("short", "��ɽ");
        set("long", @LONG
������ɽ��һ����ۣ��������Ҵ�(chuan)���������ż����������ˣ�
�˴��ɶɹ��󺣵��ﴫ˵�е��һ����������Ǽ��˳ǣ�������һ���޼ʵĴ󺣡�
LONG
        );
        set("outdoors", "taohua");
        set("exits", ([
                "west" : __DIR__"nanhu1",
        ]));

        set("item_desc", ([
                "chuan" : "����һ�Һ����������˶ɺ������Ǵ�����ƽʱҲ���������㡣\n",
        ]));

        set("navigate/locx", 0);
        set("navigate/locy", -200);

        set("cost", 2);

        setup();
}

