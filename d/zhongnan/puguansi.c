// Code of ShenZhou
// road: /zhongnan/puguansi.c

inherit ROOM;

void create()
{
        set("short","�չ���");

        set("long",@LONG
����һ��λ�����ɽ�µ�С�������ź��д�� "�չ���" ��������
����춴�����������ɽ�ıؾ�֮·����������οͶ����ڴ������Ϣ��Ҳ
��˴˴����Ҳ��Ϊ��ʢ����ǰ�ļ��������£�����һ��ʯ��(shibei)��
�����챻��Χ�ĳ��ݸ������ˡ���������һ��С·.
LONG);

		  set("item_desc",(["shibei" : "
			
			�� �� �� ��
			�� �� �� ��
			�� �� �� ��    ��
			ǧ �� ҹ ��
			�� �� �� ��    ��
			�� �� �� ��
			� Ӧ �� ��
			�� �� �� ��
			�� һ �� ��    ��
			�� �� �� Ϊ    ��
			�� ϸ �� ��    ��
			�� �� �� ��    ��
			�� �� �� ��    ��
			�� �� �� ��    ��
			�� �� �� ��    
			�� �� .  ?     ��
			
		\n",]));

        set("exits",([ "west" : __DIR__"daolu",
                      ])
           );
	  set("cost",1);
        set("fjing", 1);
	  set("objects", ([
				 __DIR__"npc/shen" : 1,
				 __DIR__"npc/lu" : 1,
	  ]));

	  set("outdoors", "zhongnan");

	  setup();

}

