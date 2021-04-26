// Code of ShenZhou
// jinding.c ��
// Shan: 96/06/22

#include <ansi.h>

inherit ROOM;
string long_desc();

void create()
{
        set("short", "��");
	set("long", (: long_desc :));
	set("exits", ([
		"northdown" : __DIR__"wanxing",
		"south" : __DIR__"huazang",
		"southwest" : __DIR__"woyun",
	]));

        set("no_clean_up", 0);
        set("outdoors", "emei" );

	set("cost", 2);
       set("fjing", 1);
	setup();
//        replace_program(ROOM);

}

string long_desc()
{
	int t;	// time of the day in minutes
	mixed *local;
	string desc;
	
	desc  = "����Ƕ���ɽ��������ˡ��˷�������أ������Ʊ���������׳����\n";
	desc += "���������������ڤ���쿪���ʴ��ɻ����������Ͻ𶥣���Ұ��Ȼ���ʣ���\n";
	desc += "���£�����Ⱥ��ӿ�̵��䣬������˿���������Զ���������ѩɽ��ب��ʣ�\n";
	desc += "����ɽֱ���񷡣\n";
/*
	local = localtime(time()*60);	
	t = local[2]*60 + local[1];

	// morning    5:00am -  7:30am   �ճ�
	// noon      10:30am - 12:00pm   �ƺ�
	// afternoon 12:00am -  2:00pm   ��� 
	// afternoon  2:00pm - 18:00pm   �ƺ�
	// night     19:00pm -  5:00am   ���

    	// 05:00 - 11:30
    	if ( t >= 300 && t < 450) {
               desc += HIR "    �����Ǹո�����һ����΢�׵Ĺ��ڶ����Ʋ����֣�һ�ֺ����е�������\n" NOR;
               desc += HIR "��ǧ�����ʱ�ڲ���ӳ���³��ֳ�����������\n" NOR;
	}
	// 11:30 - 12:30
	else if (( t >= 630 && t < 720) || ( t >= 840 && t < 1080)) {
                desc += HIC "�������ƺ�������ãã��������Ұ��Զ����ʡ��ƺ��ᵴʱ�����ڽ𶥣���\n" NOR;
		desc += HIC "̤���ƣ�����ƮƮ����֮�У�������Ѹ��ӿ��ʱ�������𶥶�������ǰ������\n" NOR;
                desc += HIC "�����г�������֮�⡣\n" NOR;
        }
	// 12:30 - 20:00
	else if ( t >= 720 && t < 840 ) {
		if( this_player()->query("kar") > random(30) ) {
                desc += HIY "���������羲���ƺ�ƽ�̣������Լ���������㱳��б��������������������\n" NOR;
                desc += HIY "�ɲ�ɫ�⻷��������Լ�����Ӱ�����س�������ɫ�����ϡ����⻷���˶�����\n" NOR;
                desc += HIY "Ӱ�ڻ��С������������ġ���������������\n" NOR;
                desc += MAG "���������������࣬�������棬������������һ��ʹ������ĳ����������㲻\n" NOR;
                desc += MAG "����Ҫ�ڴ�Ͷ���ƺ���������������������������ۣ�������ӡ�\n" NOR;
//			desc += HIM "    ����������������������\n" NOR;
		}
		else
			desc += NATURE_D->outdoor_room_description();
	}	
	// 20:00 - 05:00
	else if (( t >= 1260 && t < 1440 ) || ( t >= 0 && t < 300)) {
                desc += HIB "�����������º�����һƬ���������ֳ�һ�㡢�������ɫ�����⣬��������\n" NOR;
                desc += HIB "Խ��Խ�࣬ת�۱㲼��ɽ�ȣ��е�����өƮ�ɣ��е��緱����˸��\n" NOR;

//		desc += HIB "    ������������ơ���������\n" NOR;
	
	}
	else 
		desc += NATURE_D->outdoor_room_description();
*/
        return desc;

}


