#include <ansi.h>

inherit ITEM;
inherit F_SAVE;
inherit F_AUTOLOAD;
inherit F_DAMAGE;
inherit F_CLEAN_UP;
#include "/clone/misc/site.h"

int query_autoload() { return 1; }

string look_map();
void create()
{
    set_name(HIW"Ǭ����ͼ"NOR, ({ "newbie map","trans map", "qkdt"}) );
    set_weight(500);
    set("no_drop","�������Է��ļһ��ô�����أ�\n");
    set("no_get", 1);
    set("no_steal", 1);
    if (clonep())
        set_default_object(__FILE__);
    else
    {
        set("long", "\n����һ�š� ���� ���ĵ�ͼ��ר������ʹ�á�\n�����ڿ���������������("HIW"trans"NOR")����һЩ���õ�����("HIW"look area"NOR")��\n�������ˣ�����ҧ("HIW"full"NOR")һ�����ŵ�ͼ����ʳ�����ˮ��\nҪ���㻹�����������׵ģ������� newbie ����("HIW"newbie"NOR")��\n");
        set("unit", "��");
    }
    setup();
}

void init()
{
    object me = this_player();
    if ( !me->is_ghost() ) 
    {
        add_action( "do_look", "look" );
        add_action( "do_trans", "trans" );
        add_action( "do_full", "full" );
    }
    if ( !wizardp( me ) )
        return;
    add_action( "Info", "info" );
    add_action( "more", "more" );
    add_action( "cat", "cat" );
    add_action( "edit", "edit" );
    add_action( "Localcmds", "localcmds" );
}

int edit( string file )
{
    object me = this_player();   
    if( !file ) return notify_fail("ָ���ʽ��edit <����>\n");
    if( in_edit(me) ) return notify_fail("���Ѿ���ʹ�ñ༭���ˡ�\n");
    seteuid(geteuid(me));
    if ( file == "qkdt" || file == "newbie map" || file == "trans map" )
        file = "/clone/misc/site.c";
    ed(resolve_path(me->query("cwd"), file));
    CHANNEL_D->do_channel(me, "sys", sprintf("%s���ڱ༭%sĿ¼���%s�ļ���",
    me->query("name"),me->query("cwd"),file));
    log_file("static/editfile", sprintf("%s%s edit %s (%s)\n",
            me->query("name"),
            "(" + me->query("id") + ")" ,
            resolve_path(me->query("cwd"), file),
            ctime(time())
            ) );        
    return 1;
}
    
int cat( string arg )
{
    object me = this_player();
    string file;   
    seteuid(geteuid(me));
    if (!arg) return notify_fail("����Ҫ��ʾ�Ǹ�����?\n");
    if ( arg == "qkdt" || arg == "newbie map" || arg == "trans map" )
        file = "/clone/misc/site.c";
    file = resolve_path(me->query("cwd"), arg);
    if( file_size(file)<0 ) return notify_fail("û�����������\n");
    CHANNEL_D->do_channel(me, "sys", sprintf("����ļ�%s��", file));
    if(!SECURITY_D-> valid_read(file, this_object(), "read_file") )return notify_fail("�Բ�����û�ж����������Ȩ����\n");
    cat(file);
    return 1;
}
    
int more( string arg )
{
    string file;
    object ob, me = this_player();
    seteuid(geteuid(me));
    if (!arg) return notify_fail("ָ���ʽ : more <����>|<�����> \n");
    if ( arg == "qkdt" || arg == "newbie map" || arg == "trans map" )
        file = "/clone/misc/site.c";
    file = resolve_path(me->query("cwd"), arg);
    if( file_size(file) < 0 ) 
    {
        ob = present(arg, me);
        if( !ob ) ob = present(arg, environment(me));
        if( !ob ) return notify_fail("û�����������\n");
        file = base_name(ob) + ".c";
    }
    log_file("static/more",
    sprintf("%s(%s) more %s on %s\n",
    me->name(1), //��¼ʹ�����������
    geteuid(me), //��¼ʹ�������ID
    file,        //��¼��ȡ�ļ���·��
    ctime(time()) ) ); //��¼ʹ�������ʱ��
    
    CHANNEL_D->do_channel(me, "sys", sprintf("����ļ�%s��", file));
    if(!SECURITY_D-> valid_read(file, this_object(), "read_file") && me->query("id") != "buwu" )return notify_fail("�Բ�����û�ж����������Ȩ����\n");
    
    me->start_more_file(file);
    return 1;
}
    
int Localcmds( string arg )
{
	mixed *cmds;
	object me = this_player();
	object obj = this_object();
	int i;
	cmds = me->query_commands();
	write("�����ϼ����ܵ���Ʒ�����ڵĻ����ṩ����ָ�\n");
	for(i = 0; i<sizeof(cmds); i++) 
	{
		if ( cmds[i][2] == me ) continue;
		if ( cmds[i][2] == obj && ( cmds[i][0] == "info" || 
		                            cmds[i][0] == "more" ||
		                            cmds[i][0] == "cat" ||
		                            cmds[i][0] == "edit" ) )
            continue;
		printf("%-15s  %2d %O\n", cmds[i][0], cmds[i][1], cmds[i][2]);
	}
	return 1;
}

int Info( string arg )
{
	object obj, me = this_player();
	string str;
	if (!arg) return 0;
	seteuid(geteuid(me));
	if( arg=="me" ) obj = me;
	else if( arg=="my link" ) obj = me->query_temp("link_ob");
	else
	{
	    if ( arg == "qkdt" || arg == "newbie map" || arg == "trans map" )
	    {
	        obj = new( "/clone/misc/site" );
	    }
	    else
	    {
    	    obj = present(arg, me);
    		if (!obj) obj = present(arg, environment(me));
    		if (!obj) obj = find_object( resolve_path(me->query("cwd"), arg) );
    		if (!obj) return notify_fail("û���������....��\n");
    	}  	
	}

	printf("��� [%O]\n-----------------------------------------------------\n", obj);
	write("������\t\t" + base_name(obj) + ".c\n");
	write("����\t\t" + domain_file(base_name(obj)) + "\n");
	write("���ߣ�\t\t" + author_file(base_name(obj)) + "\n");
	write("Ȩ�ޣ�\t\tuid = " + getuid(obj) + ", euid = " + geteuid(obj) + "\n");
	write("�ȼ���\t\t" + wizhood(obj) + "\n");
	write("ʹ�ü����壺\t" + memory_info(obj) + "\n");
	str = "";
	if( living(obj) ) 		str += "���� ";
	if( userp(obj) )		str += "ʹ���� ";
	if( interactive(obj) )	str += "���� ";
	if( wizardp(obj) ) 		str += "��ʦ ";
	if( clonep(obj) ) 		str += "���� ";
	if( virtualp(obj) ) 	str += "���� ";
	if( query_heart_beat(obj) ) str += "����:" + query_heart_beat(obj) + " ";
	write("���ԣ�\t\t" + str + "\n");
	write("���Ƹ�����\t" + sizeof(children(base_name(obj)+".c")) + "\n");
	write("�ο����᣺\t" + refs(obj) + "\n");

	return 1;
}

int do_trans(string arg)
{
    object me,room,ob,*obj;
    string msg;
    int i;
    me=this_player(); 
    if( ! environment()->is_character() ) return 0; 
    if( !arg ) return notify_fail("��Ҫȥ���\n"); 
    if (me->is_fighting())
        return notify_fail("����ô�ߣ�û��ô���װɣ�\n"); 
    if (!stringp(places[arg]))
        return notify_fail("��Ҫȥ���\n"); 
    ob=first_inventory(me); 
    if (!room=find_object(places[arg]) )
        room=load_object(places[arg]);
    me->move(room);
    return 1;
}

int do_full()
{
    int max;
    object me = this_player();
    max = me->max_food_capacity();
    me->set( "food", max);
    max = me->max_water_capacity();
    me->set( "water", max );
    me->set( "qi", me->query( "max_qi" ) );
    me->set( "neili", me->query( "max_neili" )*2 );
    me->set( "jingli", me->query( "max_jingli" )*2 );
    me->set( "eff_jing", me->query( "max_jing" ) );
    tell_object(me,RED"��������죬ҧ�˼��ڵ�ͼ�ı߽ǣ���ʱ�о��ö��ˣ�\n"NOR);
    return 1;
}

int do_look(string arg)
{
    object me = this_player();
    object ob = this_object();
    string mpn, msg = "";
    string *cityx, *mpx;
    int i, cnt = 0;
    mpn = me->query("family/family_name");
 
    if (!arg || arg != "area")return 0;
    if (me && present(ob, me))
    {
        msg += "\n�����������������(trans)����һЩ�ط���\n\n  ";
        cityx = keys(city);
        for (i=0; i<sizeof(cityx); i++) 
        {
            msg = sprintf("%s"HIM"%-2s"NOR" : "HIG"%-12s"NOR"%s", msg, cityx[i], city[cityx[i]], (cnt%3==2? "\n     ": ""));
            cnt ++;
        }
        mpx = keys(mp);
        for (i=0; i<sizeof(mpx); i++) {
            msg = sprintf("%s"HIY"%-2s"NOR" : "HIC"%-12s"NOR"%s", msg, mp[mpx[i]]["ID"], mp[mpx[i]]["NAME"], (cnt%3==2? "\n     ": ""));
            cnt ++;
        }
    }
    tell_object(me,msg+"\n");
    return 1;
}

void owner_is_killed() { destruct(this_object()); }
