//room: /newjob/builder/snlslin.c ��ɼ��
//Lara 2001/12/03
inherit ROOM;
#include <ansi.h>
void create()
{        
        set("short", "��ɼ��");
        set("long", @LONG
�ߴ�ï�ܵ���ɼ�ּ�����ס����⣬�������ź��Ŀ�Ҷ����������
���ϣ��������߲���������ӡ�������ɱ档������ż����������Ұ�޵�
��У����˲����е㵨ս�ľ���
LONG
        );

        set("exits", ([   
        "south" : __DIR__"snhongping",   
        "east" : __DIR__"snsbling",
        ]));
        set("no_clean_up", 0);       
        set("invalid_startroom", 1);       
        set("cost", 1);
        setup();
}
