// rany's workroom

#include <ansi.h>

inherit ROOM;

void reset();
int valid_leave();

void create()
{
        set("short",GRN "ս��" NOR);
        set("long", @LONG
        
��԰���˹�����ƣ������˹��������ظ�������һ����ѵ������
�ƺ���û�дӲ��ҵ�ս�������ѹ���������Ϊû�м����ⳡ�����
�ҵ�ս�۶��ź���һ�������ҵ������ͷ�ϡ����õģ���Ҫ�ˣ���
һ����Ů��������������������뿪���������˵��ʱ����������
���������ʲô����ֵģ������ǹ��Ҵ��̾����������ģ�������
���ϲ����������ӣ�������ŷ��֣�����ս�����ض������ӡ�����
��������


LONG
        );
        set("no_fight", 1);
        set("objects", ([
                __DIR__"yumiko" : 1,
        ]));
                                              
        set("valid_startroom",1);
        
        set("objects", ([
        		__DIR__"qiushui" : 1,

        ]));
                                              
        set("exits", ([
                "yz" : "/d/city/kedian",
                "wr" : "/d/wizard/meeting_room",                                                             
                "gm" : "/d/gumu/dating",                                                             
        ]));

        setup();
        setup();
        //replace_program(ROOM);
}