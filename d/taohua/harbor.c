// Code of ShenZhou
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
����һ������ĸ��壬�����Ѵ��СС��ͣ���������Ҵ�������һ�Ҵ󴬴�β��
�ʣ���������������ý�̻Իͣ������´���õģ���ȴԶԶͣ��һ�ԣ���֪��ʲ
ô�á������м����ư�ˮ��æ��æȥ������Ը���㡣
LONG
        );

        set("outdoors", "taohua");

        set("exits", ([
                "east" : __DIR__"shucong",
		"north" : __DIR__"enter_m",
        ]));

        set("item_desc", ([
                "chuan" : "����һ�Һ����������˶ɺ������Ǵ�����ƽʱҲ���������㡣\n",
        ]));

        set("cost", 3);
        setup();
        replace_program(ROOM);
}
