//room: /newjob/builder/cbqiaomuw.c ���׶���ľ��
//Lara 2001/11/11
//���﷥ľʱ��������Ұ�ǻ��ܹ������
//��ľ������һ�������������ཨ��ľ�ģ���Ҫ�Ƕ���ľ��
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "��ľ��");
        set("long", 
"���ﳤ����"+HIW"����"NOR+"��"+HIR"����"NOR+"�ȴ�����������ľ�����൱ï�ܣ�����Ҳ��
ů���������������ǳ��ż���Ư����С������"+HIY"��ɫ"NOR+"�ģ�Ҳ��"HIC+"��ɫ"NOR+"�ġ���˵
�����������������ܣ����˶��쾭�������˽���������ܣ�ƽʱ��������
���ǲ��ҵ�������ġ�\n"
        );

        set("exits", ([        
        "west" : __DIR__"cbailin",
        "south" : __DIR__"cbailine",
        "north" : __DIR__"cbjumue",
        ]));
        set("no_clean_up", 0);           
        set("cost", 1);
        setup();
}
