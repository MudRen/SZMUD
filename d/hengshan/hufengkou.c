//Cracked by Roath
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "�����");
        set("long", 
"�ߵ������ɽ·ɽ·��Ȼ�䶸��խ��·һ��Ϊ�����ͱڣ�
��һ�������޵���Ԩ������ɽ���Х���������˱���������
վ�����ȡ������ڷ���ͱ���һ��ǧ����ɣ�ӭ����չ����
����ν���������ɡ������Ͼ�����ɫ�����ڡ�\n"
        );
        set("exits", ([
                "west"  : __DIR__"xuangengsong",
                "southdown"  : __DIR__"chuyundong",
                "northeast"  : __DIR__"guolaoling",
]));
        set("no_clean_up", 0);
        set("outdoors", "hengshan");
        set("cost", 1);
        setup();
        replace_program(ROOM);
}

