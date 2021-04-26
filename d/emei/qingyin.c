// Code of ShenZhou
// qingyinge.c ������
// Shan: 96/06/22
// haowen 10/10/00 add busy check in jump
inherit ROOM;

void create()
{
        set("short", "������");
	set("long", @LONG
�����Ƕ���ɽ�������󡣴˸�λ��ţ�����£����а����������к�������
����֮ˮ�������������¡������й����������ֿ�������������������˫��
�š���������������һ���׸ߵĺں�ɫ��ʯ��Ȼͦ��������ţ�ģ���֮Ϊ��ţ
��ʯ�����ű�����һʯ��(shibei)���ɴ������ϣ������Ǻ�����ջ������·��
����������ȥ�з��¡�
LONG
	);
	set("exits", ([
		"southwest" : __DIR__"zhandao1",
		"northwest" : __DIR__"bailong",
		"southeast" : __DIR__"zhongfeng",
	]));

        set("resource/water", 1);

        set("objects", ([
		__DIR__"npc/f_dizi1" :1,
                CLASS_D("emei") + "/jingxian" :1,
        ]));

        set("item_desc", ([
                "shibei" :
"ʯ������һʫԻ��\n\n"
"���������������� Ȼ �� �� �� �� ����\n\n"
"              �� �� �� �� �� �� �١�\n\n"
"���������������� �� ˫ Ϫ һ �� ����\n\n"
"              �� �� �� ˮ �� ţ �ġ�\n\n"
"����ǡ�����ʮ��ʫ����רӽ�⡰˫����������ʫ��\n"

])  ) ;

        set("no_clean_up", 0);
        set("outdoors", "emei" );
       set("fjing", 1);

	set("cost", 1);
	setup();
//	replace_program(ROOM);
}

void init()
{
	add_action("do_jump", "jump");
}

int do_jump(string arg)
{
	object me = this_player();

	if (!arg || arg != "ţ��ʯ" ) return 0;

        if(me->is_busy())
                {
                tell_object(me,"��������æ���أ�\n");
                return 0;
                }     
	message_vision("$Nһ������ţ��ʯ��ȥ��", me);

	if ( me->query_skill("dodge") < 30+random(6) ) {
		message_vision("��ϧ�Ṧ���̫ǳ��Ծ�����ʯ����֮����Ҳ֧�ֲ�ס��\nֱ���뽭�У�һ�¾ͱ��ļ��Ľ��������Ӱ�����ˡ�\n", me);
		me->set_temp("last_damage_from", "�������������ˡ�");
		me->die();
	}
	else {
		message("vision", "\n", environment(me));
		me->move(__DIR__"niuxin");
		message("vision", me->name() + "�����ɽ������˹�����\n", 
			environment(me), ({me}) );
	}
	return 1;
}
