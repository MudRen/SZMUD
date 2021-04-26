// Code of ShenZhou
//Ǳ���� /d/shenlong/qianlong
// ALN Sep 9 / 97

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "Ǳ����");
        set("long", @LONG
���������̵�Ǳ���ã��������Ŵ����Σ������������Ű�ʣ�����������
ʹ���ڴ��������£�����ǽ��������ǲ����Խ���˵صġ�
LONG
        );

	set("exits", ([
                "out" : __DIR__"zhulin1",
        ]));
	set("cost", 1);

	set("objects", ([
                  "/kungfu/class/shenlong/hong" : 1,
                  "/kungfu/class/shenlong/su" : 1,
        ]));
        setup();
}

void init()
{
        object me = this_player();
        object *inv;

        if( !(me->query("family/family_name") == "������" || me->query("sg/spy")) ) {
                inv = all_inventory(this_object());
                for(int i = 0; i < sizeof(inv); i++ )
                        if( (inv[i]->query("family/family_name") == "������" || inv[i]->query("sg/spy")) && living(inv[i]) )
                                inv[i]->kill_ob(me);
                me->start_busy(1);
        }
}
