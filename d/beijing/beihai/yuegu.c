//Cracked by Roath
//dlc

inherit ROOM;

void create()
{
	set("short", "�Ĺ�¥");
	set("long", @LONG
�Ĺ�¥ƽ��Ϊһ�����Σ����ȶ�ʮ��麣�����Χ���������������ʽ¥�ݡ�
������ϣ�÷���(tie)ʯ�̡�ɽ���ϵ�׺��ɽ��ͥ�󣬸����������£���Ķ���ҡ�
���ƾ�̬ͤ��ˮ���򡢸�¶�����ҡ�Ҿɽͤ�ȡ�
LONG
	);
	set("cost", 2);
        set("item_desc", ([
	"tie" : "����֮����ѩʱ������������֮���������������ߡ���Զ����\n",
	    ]));
   
	set("exits", ([
                "northeast" : __DIR__"yilan",
                "southup" : __DIR__"qingxiao",
        ]));
	
	
	setup();
	replace_program(ROOM);
}
