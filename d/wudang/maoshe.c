//Cracked by Roath
//��Ӣ��é�� by maco


inherit ROOM;

string long_desc();
string day_event(){ return NATURE_D->outdoor_room_event();}

void create()
{
	set("short", "é��");
	set("long", (: long_desc :));
	
	set("exits", ([
		"east" : __DIR__"doushi",
        "out" : __DIR__"kongdi",
		]));
	
	set("objects", ([
		"/kungfu/class/taohua/chengying" : 1,
		]));
	
	set("cost", 1);
	set("cy_home",1);
    setup();
}

string long_desc()
{
	string desc;

        desc  = "����é��֮�У����ܰ���򵥣�����ʮ���Ž࣬һ�����Ϸ���������룬��
�Ǵ�����ȴ����ȫ�µģ���Ȼһ��֮΢������Ҳ������һ����˼��������һ��С
���䣬����һ��С�����ڣ�";

        if (day_event() == "event_night" || day_event() == "event_midnight"){
desc += "�¹⵭�����Ӵ���������������ڵ��¡�\n" ;
	}
	else if (day_event() == "event_evening"){
desc += "һĨ�����Դ���������������ǻƻ�ʱ�֡�\n" ;
	}
        else {
desc += "����Ӵ�������������յõ��Ϸ���֮��һƬ������\n";
	}
        return desc;
}
