// Code of ShenZhou
//�﷿ /d/shenlong/huofang
// ALN Sep / 97

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "�﷿");
        set("long", @LONG
�����������̵Ļ﷿�����ӵ�һ���Ǹ���¯���Ա���һ����ͷ����������
�񣬹��ڲ�֪����ʲô������������ζ�Ѿ�������ð��಻ע�ˡ�
LONG
        );

        set("exits", ([
                "south" : __DIR__"shibanlu",
        ]));
        set("objects",([
                "/d/shenlong/obj/hongcha" : 3,
                "/d/shenlong/obj/shegeng" : 2,
        ]));
        set("cost", 1);

        setup();
}
