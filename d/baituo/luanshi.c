// road: /baituo/luanshi.c

inherit ROOM;

void create()
{
        set("short","��ʯ��");

        set("long",@LONG
�����ز����˴��СС��ɽʯ��ʯ϶��ż��������Щ�߰����룬��
�Ʋ�һ���Ӳݣ�ʯ���Ｘֻ�ֻ�ɫ������Ѹ�ٵ������ţ�
LONG);

		set("exits",([ 
			"east" : "/d/xingxiu/bthill",
		]));

		set("cost",2);
		set("outdoors", "baituo");
        setup();

        replace_program(ROOM);
}
