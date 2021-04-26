//�Զ���Ʊ����
//written at 14/05/2002 by Karlopex@sz

#include <localtime.h>
#include <ansi.h> 
inherit ITEM;
inherit F_SAVE;

string *opt1 = ({ 
"25��������",
"30��������",
"35��������",
"40��������",
"45��������",
"55��������",
"65��������",
"99��������",
"�������",
"���µ�һ����",
});
mapping menpai = ([
	"hs":"��ɽ��",
	"xx":"������",
	"wd":"�䵱��",
	"dl":"����μ�",
	"gb":"ؤ��",
	"xs":"ѩɽ��",
	"th":"�һ���",
	"gm":"��Ĺ��",
	"sl":"������",
	"qz":"ȫ���",
	"em":"������",
	"bt":"����ɽ",
	"kl":"������",
/*	"mj":"����",
	"xy":"��ң��",
	"ry":"�������",
	"ts":"��ɽ��",
	"lj":"���չ�",
	"mr":"����Ľ��",*/
]);
 
string query_save_file()
{
	return "/data/npc/xuanpiao";
}
int check_time(object piao);
string check_piao(object piao);

void create() 
{ 
	set_name(WHT"ѡƱ�Զ���Ʊ��"NOR, ({"auto reader" ,"reader"})); 
	set("title", HIG"���ݱ�����"NOR); 
	set_weight(100000000);
	set_max_encumbrance(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "̨");
		set("long","����һ̨���ݱ���Э���Ʒ��"WHT"ѡƱ�Զ���Ʊ��"NOR"��\n�����֪�����ʹ�ã�����"HIG"zhinan"NOR"ָ�\n"); 
		set("value", 1000000);
		set("no_get",1);
		set("piao",0);
		set("shou",0);
		set("no_clean_up", 1);
	}
    	if ( restore() ) restore_object("/data/npc/xuanpiao");  
	setup();
} 

void init() 
{ 
        object me = this_player();
	if ( wizhood(me) == "(admin)" || wizhood(me) == "(arch)" || getuid(me) == "lnere"){
		add_action("do_set_time", "set_time");
		add_action("do_set_name", "set_name");
		add_action("do_check", "check");
	}
	add_action("do_qupiao", "na"); 
	add_action("do_qupiao", "qu"); 
	add_action("do_yanpiao", "yan"); 
	add_action("do_yanpiao", "dui");
	add_action("do_zhinan", "zhinan");
}
int do_set_time(string arg)
{
        object me = this_player();
        int year, mon, day, hour, min;

        if ( !arg || arg == "" ){
        	if ( query("settime") == "ok" )
			return notify_fail("�����õ���"+query("year")+"��"+query("mon")+"��"+query("day")+"��"+query("hour")+"��"+query("min")+"�֡�\n");
		else return notify_fail("�밴<set_time ��,��,��,ʱ,��>��ȷ���롣\n");
	}

        if ( sscanf(arg , "%d,%d,%d,%d,%d" , year, mon, day, hour, min) != 5)
		return notify_fail("�밴<set_time ��,��,��,ʱ,��>��ȷ���롣\n");

	if ( year < 2000 )
		return notify_fail("��ݲ��ԣ�������2000���ϵ����֡�\n");

	if ( mon > 12 )
		return notify_fail("�·ݲ��ԣ�������12���µ����֡�\n");

	if ( ( mon <= 7 && mon%2 == 1 ) || ( mon >= 8  && mon%2 != 1 ) )
		if ( day > 31 )	return notify_fail("���ڲ��ԣ�"+chinese_number(mon)+"��ֻ��31�졣\n");
	else if ( mon == 2 ){
 		if ( year%4 != 0 && day > 28 )
			return notify_fail("���ڲ��ԣ������"+chinese_number(mon)+"��ֻ��28�졣\n");
		else if ( year%4 == 0 && day > 29 )
			return notify_fail("���ڲ��ԣ������"+chinese_number(mon)+"��ֻ��29�졣\n");
	}else if ( day > 30 ) return notify_fail("���ڲ��ԣ�"+chinese_number(mon)+"��ֻ��30�졣\n");
	
	if ( hour == 24 ) hour = 0;

	if ( hour > 23 ) return notify_fail("Сʱ���ԣ�һ��ֻ��24Сʱ��\n");
	
	if ( min == 60 ) min = 0;

	if ( min > 59 ) return notify_fail("���Ӳ��ԣ�һСʱֻ��60���ӡ�\n");	

	set("yeer" , year);
	set("mon" , mon);
	set("day" , day);
	set("hour" , hour);
	set("min" , min);
	set("settime" , "ok");	
	tell_object(me,"��Ľ�ֹʱ��������ϣ������õ���"+year+"��"+mon+"��"+day+"��"+hour+"��"+min+"�֡�\n");
	save();
	return 1;
}

int do_set_name(string arg)
{
        object ob, me = this_player();
        string name, menu, menus, names = "";
        int i, j;
	string *mpx, mpname;
	mpx = keys(menpai);
	menus = "		25��������\n";
	menus += "		30��������\n";
	menus += "		35��������\n";
	menus += "		40��������\n";
	menus += "		45��������\n";
	menus += "		55��������\n";
	menus += "		65��������\n";
	menus += "		99��������\n";
	menus += "		�������\n";
	menus += "		���µ�һ����\n";
	menus += "�����ŵĴ����У�\nhs �� ��ɽ��    xx �� ������    wd �� �䵱��    kl �� ������\nxs �� ѩɽ��    th �� �һ���    gm �� ��Ĺ��    sl �� ������\nqz �� ȫ���    em �� ������    bt �� ����ɽ    gb �� ؤ��\ndl �� ����μ�\n";
        if ( !arg || arg == "" ){
        	if ( query("setname") == "ok" )
			return notify_fail("���Ѿ��ѱ�����������������ˡ�\n");
		else return notify_fail("�밴<set ��Ŀ ����>�ĸ�ʽ��ȷ���롣\n��Ŀ�����ɴ������£�\n"+menus);
	}

	if ( arg == "set ok" ){
		set( "setname" , "ok" );
		tell_object(me,"�����еı���������������ϡ�\n");
		save();
		return 1;
	}

        if ( sscanf(arg , "%s %s" , menu, name) != 2)
		return notify_fail("�밴<set_name ��Ŀ ����>�ĸ�ʽ��ȷ���롣\n");

	if ( name == "none" ){
		set(menu,"����δѡ");
		tell_object(me,"�����õ���"+menu+"��Ŀ��û�е�����\n");
		return 1;
	}
	
	if ( menu == "�������" ){
		i = sizeof(explode(name, "\," ));
		if (i != 5)
		{ 
			write("��д��������������ˣ������������������\n");				
	                return 1;
		}
		for(j=0;j<i;j++)
		{
			if (!objectp(ob = find_player(explode(name, "\," )[j])))
			{
				ob = new(USER_OB);
			        ob->set("id", explode(name, "\," )[j]);   
				if( !ob->restore() ) {
			        	write(HIR+ explode(name, "\," )[j] + "��δע�ᣡ"NOR"�������������������\n");
					destruct(ob);
			                return 1;
				}
			}
			names += ob->name()+"("+explode(name, "\," )[j]+")��";	
		}
		names = names[0..<3];
		set(menu,explode(names, "\��" ));
		tell_object(me,"�����õ���"+menu+"��Ŀ��������"+names+"��\n");
		save();
		return 1;
	}else if ( menu == "���µ�һ����" ){
		for (int k=0; k<sizeof(mpx); k++) {
			if (name == mpx[k] || name == menpai[mpx[k]])
			{
				if (name == mpx[k]) name = menpai[mpx[k]];
				write("�������"+menu+"������"+name+"��\n"NOR);
				save();
				return 1;
			}
		}
		write(HIR + name + "������Ч����������룡�������������µ�һ���ɡ�\n"NOR);
		return 1;
	}	
	if (!objectp(ob = find_player(name)))
	{
		ob = new(USER_OB);
	        ob->set("id", name);   
		if( !ob->restore() ) {
	        	write(HIR+ name + "��δע�ᣡ"NOR"����������"+opt1[i]+"�ĵ�ʤ�ߡ�\n");
			destruct(ob);
	                return 1;
		}
	}

	name = ob->name()+"("+name+")";
	set( menu , name);
	tell_object(me,"�����õ���"+menu+"��Ŀ��������"+name+"��\n");
	save();
	return 1;
}

int do_check()
{

	string zt = "�������ڿ����С�\n";
	if ( query("piao") ) zt += "����Ŀǰ����"+chinese_number(query("piao"))+"�ŵ�һ�졾���ݡ��������ѡƱ��\n";
	if ( query("shou") ) zt += "����Ŀǰ�ջ�"+chinese_number(query("piao"))+"�ŵ�һ�졾���ݡ��������ѡƱ��\n";
	if ( query("busy") == "start" ) zt += "����Ŀǰ���ڶҽ��С�\n";
	write(HIG+zt+NOR);
	return 1;
}

int do_qupiao(string arg)
{
	object newpiao, me = this_player();

	if ( !arg || arg == "" ) return notify_fail("��Ҫ��ʲô��\n");

	if ( arg != "xuanpiao" && arg != "piao")  return notify_fail("��Ҫ�ö�������û�С�\n");
	
	if( present(arg, me) || present(me->query("id")+"'s piao", me) )
		return notify_fail("ѡƱ����������ϡ�\n");
	
	newpiao = new(__DIR__"piao");
	newpiao->move(me);
	add("piao" , 1);
	message_vision(HIG"$N��$n"HIG"���ó���һ�ű������ѡƱ��\n"NOR, me, this_object());	
	save();
	return 1;
}

int do_yanpiao(string arg)
{
	object piao, me = this_player();

	if ( !arg || arg == "" ) return notify_fail("��Ҫ��ʲô��\n");
	if ( query("busy") == "start" ) return notify_fail("��Ҫ��ʲô��\n");
	if ( arg != "xuanpiao" && arg != "piao" && arg != me->query("id")+"'s piao" )
		return notify_fail("���������������鲻�ˡ�\n");
	
	if ( arg != me->query("id")+"'s piao" ) arg = me->query("id")+"'s piao";
	
	if ( !objectp( piao = present( arg , me ) ) )
		return notify_fail("������û������������\n");

	if ( !check_time( piao ) )
		return notify_fail("�����̫����Ʊ�Ѿ����ϡ�\n");

	message_vision(HIG"$N����õı������ѡƱ�Ž���$n"HIG"���ʼ�ҽ���\n"NOR, me, this_object());
	piao->move(this_object());
	check_piao( piao );
	set("busy","stop");
	add("shou",1);
	return 1;		
}
int check_time(object piao)
{
	mixed *local;
	int year, mon, day, hour, min, time2;
	local = localtime(piao->query("done_time"));
       	if ( query("settime") != "ok" )
       		return piao->query("done_time") < time();
	year = query("year");
	mon = query("mon");
	day = query("day");
	hour = query("hour");
	min = query("min");
	if ( local[LT_YEAR] <= year ) return 1;
	if ( local[LT_MON] <= mon ) return 1;
	if ( local[LT_MDAY] <= day ) return 1;
	if ( local[LT_HOUR] < hour ) return 1;
	if ( local[LT_MIN] < min ) return 1;	
}
void check_piao(object piao)
{
	int i, j, cnt, count;
	string *name;
	name = piao->query("�������");
	set("busy","start");
	for(i=0;i<sizeof(opt1);i++){
		if ( opt1[i] == "�������" ){
			for(j=0;j<sizeof(name);j++){
				if (member_array(name[j], query(opt1[i])) != -1)
					cnt++;
			}
		}else if (piao->query(opt1[i]) == query(opt1[i]))
			count++;
	}
	if ( cnt == 5 ) count++;
	if ( count > 0){
		write("�㹲����"+chinese_number(count)+"����Ŀ�������������"+chinese_number(cnt)+"����\n");
		if ( count == 10 )
		write("��ϲ����ϲ�����н��ˣ���õ���50�㹱�׶ȵĽ�����\n");
		this_player()->add("shenzhou/pts",50);
	}else write("���ź�����δ�н���\n");
}

int do_zhinan()
{
        object me = this_player();
        string str = "			�����������£�\n";
	if ( wizhood(me) == "(admin)" || wizhood(me) == "(arch)" || getuid(me) == "lnere"){
		str += "	һ��<set_time ��,��,��,ʱ,��>���ñ���Ʊ�����ʱ�䡣\n";
		str += "	����<set_name ��Ŀ, ����>�������ı�������\n";
		str += "	����<check>��鱾��״̬��\n";
		str += "	�ġ�<[qu | na] piao>ȡƱ��\n";
		str += "	�塢<[yan | dui] piao>��Ʊ���Լ��ó������\n";
	}else{
		str += "	һ��<[qu | na] piao>ȡƱ��\n";
		str += "	����<[yan | dui] piao>��Ʊ���Լ��ó������\n";
	}
	write (HIG+str+NOR);
	return 1;
}
		
	
	
	
	
		