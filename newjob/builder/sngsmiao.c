//room: /newjob/builder/sngsmiao.c ��ɼ��
//Lara 2001/12/03
inherit ROOM;
#include <ansi.h>
void create()
{        
        set("short", "��ɼ��");
        set("long", @LONG
���ﳤ��һ�ŲԾ�ͦ�εĹ�ɼ����������ǧ�ꡣ���������׻�����Χ
�ľ���Ϊ�˼������飬�����֣��ڹ�ɼ�ײ��׻�������һ����������
һ���ļ���𲻶ϡ�����Ρ��ͦ�Σ��������죬֦Ҷ��ï����Ũ���㡣ÿ
������ѩ��ʱ������˪��ӭ�籩�����ӲԴ䣬����ů����ʱ�ڣ���Ҷ����
���������������١�
LONG
        );

        set("exits", ([   
        "north" : __DIR__"snssping",   
        "west" : __DIR__"snmuyuping",
        ]));
        set("no_clean_up", 0);       
        set("invalid_startroom", 1);       
        set("cost", 1);
        setup();
}
