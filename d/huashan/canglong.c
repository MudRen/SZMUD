// Code of ShenZhou
// canglong.c

inherit ROOM;

void create()
{
        set("short", "������");
	set("long", @LONG
��ɽ�������յ��Ǳ��壬����֮����͵����ǲ����롣�����
Լ���ף����һ�ף�����ɽ֮·������ɽ��֮�ϣ����༹�¹⻬ͦ�Σ���
���������䣬���������������һʯ��(shibei)��
    ��������������ɽ��·���������������ķ��·�������ǻ�ɽ���մ�
֮һ�������������¡���
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
	  	"northdown" : __DIR__"husun",
  		"southdown" : __DIR__"zhenyue",
  		"westup" : __DIR__"sheshen",
		"eastup" : __DIR__"fengding",
	]));

        set("objects", ([
                __DIR__"npc/haoke" : 1,
        ]));

        set("item_desc", ([
		"shibei" :
"ʯ�����ż������֣�������֮Ͷ�鴦������˵���꺫�����ϴ���֮����\n"
"Ҳ��������������ΪҪ����ɽ�ϣ�����ɽ��д��Ͷ�������ͼ��˾��𡣺�\n"
"�����ǻ����ص��ع�������ɽ�����Ӱ������ŵ������ġ�\n"
])  ) ;

        set("no_clean_up", 0);
        set("fjing", 1);
        set("outdoors", "huashan" );

	set("cost", 5);
        setup();
        replace_program(ROOM);
}
 
