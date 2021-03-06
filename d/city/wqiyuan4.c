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
    set_name(HIW"乾坤地图"NOR, ({ "newbie map","trans map", "qkdt"}) );
    set_weight(500);
    set("no_drop","这可是你吃饭的家伙，怎么能扔呢？\n");
    set("no_get", 1);
    set("no_steal", 1);
    if (clonep())
        set_default_object(__FILE__);
    else
    {
        set("long", "\n这是一张【 神州 】的地图，专供新手使用。\n你现在可以在它的引导下("HIW"trans"NOR")到达一些有用的区域("HIW"look area"NOR")。\n如果你饿了，可以咬("HIW"full"NOR")一口这张地图补充食物和饮水。\n要是你还有其他不明白的，请输入 newbie 命令("HIW"newbie"NOR")。\n");
        set("unit", "张");
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
    if( !file ) return notify_fail("指令格式：edit <档名>\n");
    if( in_edit(me) ) return notify_fail("你已经在使用编辑器了。\n");
    seteuid(geteuid(me));
    if ( file == "qkdt" || file == "newbie map" || file == "trans map" )
        file = "/clone/misc/site.c";
    ed(resolve_path(me->query("cwd"), file));
    CHANNEL_D->do_channel(me, "sys", sprintf("%s正在编辑%s目录里的%s文件。",
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
    if (!arg) return notify_fail("你想要显示那个档案?\n");
    if ( arg == "qkdt" || arg == "newbie map" || arg == "trans map" )
        file = "/clone/misc/site.c";
    file = resolve_path(me->query("cwd"), arg);
    if( file_size(file)<0 ) return notify_fail("没有这个档案。\n");
    CHANNEL_D->do_channel(me, "sys", sprintf("浏览文件%s。", file));
    if(!SECURITY_D-> valid_read(file, this_object(), "read_file") )return notify_fail("对不起，你没有读这个档案的权力。\n");
    cat(file);
    return 1;
}
    
int more( string arg )
{
    string file;
    object ob, me = this_player();
    seteuid(geteuid(me));
    if (!arg) return notify_fail("指令格式 : more <档名>|<物件名> \n");
    if ( arg == "qkdt" || arg == "newbie map" || arg == "trans map" )
        file = "/clone/misc/site.c";
    file = resolve_path(me->query("cwd"), arg);
    if( file_size(file) < 0 ) 
    {
        ob = present(arg, me);
        if( !ob ) ob = present(arg, environment(me));
        if( !ob ) return notify_fail("没有这个档案。\n");
        file = base_name(ob) + ".c";
    }
    log_file("static/more",
    sprintf("%s(%s) more %s on %s\n",
    me->name(1), //记录使用命令的人名
    geteuid(me), //记录使用命令的ID
    file,        //记录读取文件的路径
    ctime(time()) ) ); //记录使用命令的时间
    
    CHANNEL_D->do_channel(me, "sys", sprintf("浏览文件%s。", file));
    if(!SECURITY_D-> valid_read(file, this_object(), "read_file") && me->query("id") != "buwu" )return notify_fail("对不起，你没有读这个档案的权力。\n");
    
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
	write("你身上及四周的物品与所在的环境提供以下指令：\n");
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
    		if (!obj) return notify_fail("没有这样物件....。\n");
    	}  	
	}

	printf("物件 [%O]\n-----------------------------------------------------\n", obj);
	write("档案：\t\t" + base_name(obj) + ".c\n");
	write("领域：\t\t" + domain_file(base_name(obj)) + "\n");
	write("作者：\t\t" + author_file(base_name(obj)) + "\n");
	write("权限：\t\tuid = " + getuid(obj) + ", euid = " + geteuid(obj) + "\n");
	write("等级：\t\t" + wizhood(obj) + "\n");
	write("使用记忆体：\t" + memory_info(obj) + "\n");
	str = "";
	if( living(obj) ) 		str += "生物 ";
	if( userp(obj) )		str += "使用者 ";
	if( interactive(obj) )	str += "线上 ";
	if( wizardp(obj) ) 		str += "巫师 ";
	if( clonep(obj) ) 		str += "复制 ";
	if( virtualp(obj) ) 	str += "虚拟 ";
	if( query_heart_beat(obj) ) str += "心跳:" + query_heart_beat(obj) + " ";
	write("属性：\t\t" + str + "\n");
	write("复制个数：\t" + sizeof(children(base_name(obj)+".c")) + "\n");
	write("参考连结：\t" + refs(obj) + "\n");

	return 1;
}

int do_trans(string arg)
{
    object me,room,ob,*obj;
    string msg;
    int i;
    me=this_player(); 
    if( ! environment()->is_character() ) return 0; 
    if( !arg ) return notify_fail("你要去哪里？\n"); 
    if (me->is_fighting())
        return notify_fail("想这么走，没那么容易吧！\n"); 
    if (!stringp(places[arg]))
        return notify_fail("你要去哪里？\n"); 
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
    tell_object(me,RED"你张起大嘴，咬了几口地图的边角，顿时感觉好多了！\n"NOR);
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
        msg += "\n你可以在它的引导下(trans)到达一些地方：\n\n  ";
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
