//Cracked by Roath
//baoyuan.c ��ԴǮׯ
// ssy

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIY"��ԴǮׯ"NOR);
        set("long", @LONG
���Ǿ���������һ��Ǯׯ�������е���Ʊ�����ǳ��ã�ͨ��ȫ����ǽ����
��һ�Ų���(bugao)��Ǯׯ�ƹ�ͻ��ææµµ�ع����š�
LONG
        );

        set("item_desc", ([
			   "bugao" : "
Ǯׯҵ�񣺴��(deposit)��ȡ��(withdraw)���һ�(convert)��
\n",
        ]));
        set("objects", ([
	       __DIR__"npc/bankhuoji" : 1,
        ]));

        set("no_drop",1);
        set("exits", ([
               "west" : __DIR__"fuchengdajie_n",
        ]));

        set("day_shop", 1);
        set("cost", 0);
        setup();
}


