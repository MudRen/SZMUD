// CODE BY SCATTER
// V. 1.0
// describing BY SNOWLF

#include <ansi.h>

inherit ROOM;

void create()

{
        set("short", HIC"������"NOR);
        set("long", @LONG       
����һ�����ͨ�Ĵ����ң��������ȴ������²�Զ��������ǽ�ĵط��и���
��̨���л�¯(stove)�ͷ��䣬ǽ�ǻ���һ������(box)�������װԭ���ϻ�ľ̿
������֮���õİɡ�
LONG
        );

	set("exits", ([
                "west" : "/newjob/tiejiang/datiechang.c"
				]));
        set("item_desc", ([
                        "stove": "������¯�ߣ��������£������ǰ���ػ������������ù������ƶ����أ�\n",
                        "box": "�����������������ҿ���������û�����õ��ϵĶ����ɡ�\n",
                        "��¯": "������¯�ߣ��������£������ǰ���ػ������������ù������ƶ����أ�\n",
                        "����": "�����������������ҿ���������û�����õ��ϵĶ����ɡ�\n",
                        ]));     

		set("objects",([
                "/newjob/tiejiang/obj/datietai.c": 1,
		]));

        setup();
}

