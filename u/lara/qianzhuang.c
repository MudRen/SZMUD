 // MODIFY BY SCATTER
// 12/01/01
// V. 1.2
// Lara 2001/12/05
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIY"Ǯׯ"NOR);
        set("long", @LONG
����һ�����ֺŵ�Ǯׯ�����м��������ʷ����ȫ�����ض��зֵꡣ������
����Ʊ�����ǳ��ã�ͨ��ȫ����ǽ��������һ�Ų���(bugao)�������߾���
���Դ�����ߵĵط��ˡ�
LONG
        );

        set("item_desc", ([
                "bugao" : "
����������ռ������ݡ�����Ǯׯ�Ӽ������ɻ�ɽ�ɴ����
�����������֡�һ��Ǯׯҵ���վɡ�

        ��������ӭ����
        �������˲�����

�� ������ʦ������
\n",
        ]));

        set("no_drop",1);
        set("exits", ([
                "south" : __DIR__"dongdajie3",
                "east" :  __DIR__"itembank",
        ]));

        set("objects", ([
                __DIR__"npc/huang" : 1
        ]));
        set("day_shop", 1);
        set("cost", 0);
        setup();
}
void init()
{
        int balance;

        if( !this_player()->query("newsaver") ) 
        {
                balance = this_player()->query("balance");
                if( balance >= 1000000 ) balance = balance/10;
                if( balance >= 1000000 ) balance = 1000000;
                this_player()->set("balance", balance);
                this_player()->set("newsaver", 1);
        }
        
        this_player()->save();
}
