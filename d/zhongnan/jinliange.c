// Code of ShenZhou
// road: /zhongnan/jinliange.c

inherit ROOM;

void create()
{
		  set("short","������");

		  set("long",@LONG
�������λ�����ɽɽ���䣬������Ϊ��Ҫ������������һ����ڴ�
��ӿȪ��Ȫˮ����͸�����������ˣ��ڵ�����Ϊ�������������ر����ˣ�
ֻΪ��ȡ����ˮ���ݲ衣����ǰ��һ��ʯ��(shibei)������һ������ά
��ʫ�����Ͽ�ȥ��һ��ɽ·����������һ�����ѵ�ɽ·��
LONG);

	  set("item_desc",(["shibei" : "



		�� �� �� ̫
		Ͷ Ұ �� ��
		�� �� �� ��  ��
		�� �� �� ��  ��  
		�� �� �� ��  ɽ
		�� �� �� ��
		�� �� �� ��
		ˮ �� �� ɽ  ��
		�� �� �� ��  ά
		�� �� �� ��
		�� �� �� ��
		�� �� �� ��


					\n",]));

        set("exits",([ "westup" : __DIR__"shanlu3",
                        "southdown" : __DIR__"shanlu2",
                      ])
           );
	  set("cost",2);
        set("fjing", 1);
	  set("outdoors", "zhongnan");

        setup();

        replace_program(ROOM);
}
