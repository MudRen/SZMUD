// Code of ShenZhou
// room: /d/xingxiu/nanjiang.c
// Jay 3/17/96
// Ryu 5/10/97
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
���������׶���ԭ֮��һ�󶼻ᣬ����İ����ϣ������챦����
����֮�������Ʒ���Ȳ���ö�١����������Դ����¡���������̶ӣ�
Ҳ��Զ�����������á���˹���������֡������������������ڵ��ϵ�
��̺�ϣ��Ա߶������Ļ���ǽ���и����ӣ��Ǹ���Ŀ��(sign)��
LONG
        );
        set("exits", ([ 
        "east" : __DIR__"beijiang",
]));
        set("objects", ([
                __DIR__"npc/maimaiti": 1 ,
		__DIR__"npc/trader": 1,
]));
        set("item_desc", ([ /* sizeof() == 1 */
"sign" : "������д����
��ԭǮ��ͨ�á�
        ���̾ƺ�(hu)       һ����
        ��(nang)           ��ʮ��
        ����(fire)         һ����
        ���ܹ�(gua)        ��ʮ��
        ������(dongbula)   һ����
	�ⵣ(biandan)      ��ʮ��
	�廨��(xiuhua zhen)һ������
        ���(liuhuang)    ��������
	˿��(Si juan)	   ��������	
        ������(horse)      һǧ�� ( ���� )
\n"
]));
        set("no_clean_up", 0);

	set("cost", 0);
        setup();
        replace_program(ROOM);
}

 
