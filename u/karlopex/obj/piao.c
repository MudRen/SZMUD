//xuanpiao.c
//create by rama@sz

inherit ITEM;

#include <ansi.h>
#include <mudlib.h>

void get_id( string arg);
int check_legal_id(string id);
int check_id(string id, int x);
void confirm_xuan(string yn);
void get_menpai(string arg);
int check_menpai(string arg);
string *opt1 = ({ 
"25岁以下组",
"30岁以下组",
"35岁以下组",
"40岁以下组",
"45岁以下组",
"55岁以下组",
"65岁以下组",
"99岁以下组",
"五绝得主",
"天下第一门派",
});
int *age = ({ 
14,25,30,35,40,45,55,65,99,200,
});
mapping menpai = ([
	"hs":"华山派",
	"xx":"星宿派",
	"wd":"武当派",
	"dl":"大理段家",
	"gb":"丐帮",
	"xs":"雪山派",
	"th":"桃花岛",
	"gm":"古墓派",
	"sl":"少林派",
	"qz":"全真教",
	"em":"峨嵋派",
	"bt":"白驼山",
	"kl":"昆仑派",
/*	"mj":"明教",
	"xy":"逍遥派",
	"ry":"日月神教",
	"ts":"天山派",
	"lj":"灵鹫宫",
	"mr":"姑苏慕容",*/
]);
string mpl = "hs ： 华山派    xx ： 星宿派    wd ： 武当派    kl ： 昆仑派\nxs ： 雪山派    th ： 桃花岛    gm ： 古墓派    sl ： 少林派\nqz ： 全真教    em ： 峨嵋派    bt ： 白驼山    gb ： 丐帮\ndl ： 大理段家\n";

string *msg=({"","","","","","","","","","",""});
string temp="";
string mpname, name, wujue = "";
int i=0, cnt=0;

void create()
{
        set_name("比武大会选票", ({ "xuan piao","piao" }));
        set_weight(10);
        set("long","这是一张比武大会选票。
上面写着：
        25岁以下组：
        30岁以下组：
        35岁以下组：
        40岁以下组：
        45岁以下组：
        55岁以下组：
        65岁以下组：
        99岁以下组：
        五绝得主(不分名次,猜中既可)：
        天下第一门派：
你可以用xuan来填写选票。\n");
        set("unit", "张");
        set("value", 0);
        setup();
              
}

void init()
{
        add_action("do_xuan","xuan");
}

int do_xuan()
{
        object ob = this_object();
        if( ob->query("done",1))
                return notify_fail("选票不能更改。\n");
        if( i>=10)
        {
		if ( !ob->query_temp("quit") ){
	                write(HIR"此选票只能够选择一次，一经确认就无法更改！\n"NOR);
	                write("你选好了么，如果选好了就输入“Y”或者“y”？(Yes/No)");
	                }
                input_to( (:confirm_xuan :) );
                return 1;
        }
	if (i == 0){
		write(HIW"填写的注意事项：\n"NOR);
		write(HIY"１、此选票每人只有一份。\n");
		write("２、此选票只能够选择一次，一经确认就无法更改！\n");
		write("３、如有不想选的项目用“no”跳过。\n");
		write("３、如有不想再选就用“tuichu”退出选择。\n\n\n"NOR);
	}
	if (i == 9){
		write("现在『" + INTERMUD_MUD_CNAME + "』中的门派有以下可选：\n"+HIG+mpl+HIC+"选择的时候写缩写拼音或者中文名都可以。\n"NOR);
       		write("你觉得"+opt1[i]+"是哪个门派：");
	        input_to( (: get_menpai :));
		return 1;
	}else if (i == 8)
       		write("你觉得"+opt1[i]+"(不分名次,猜中既可)是哪五位高手：");
	else write("你觉得"+opt1[i]+"谁会赢：");
        input_to( (: get_id :));
        return 1;
        
}

void get_id( string arg)
{
	int a, b;
        if(arg != "no" && arg != "tuichu")
	{
	        arg = lower_case(arg);
		if (i == 8 && arg[0..0] != ",")
		{
			b = sizeof(explode(arg, "\," ));
			if (b != 5)
			{ 
        			write(ESC + "[1A" + ESC + "[256D"+"你写的人数不是五个人，重新写一下你选的五绝：");				
		                input_to("get_id");
		                return;
			}
			for(a=0;a<b;a++)
			{
		  	        if(!check_id(explode(arg, "\," )[a], i))
				{
			                input_to("get_id");
			                return;
				}
				msg[i] += name;	
			}
			msg[i] = msg[i][0..<3];
			this_object()->set(opt1[i],explode(msg[i], "\，" ));
			write(wujue);
		}else if(!check_legal_id(arg) 
	          || !check_id(arg, i))
	        {
	                input_to("get_id");
	                return;
	        }else{
		        msg[i]=name;	        
			this_object()->set(opt1[i],msg[i][0..<3]);
		}
	}else{
		if (arg == "no"){
			write(ESC + "[1A" + ESC + "[256D" + HIG +opt1[i]+"，此项你未选择。\n"NOR);
			msg[i]="此项未选。";
		}else if ( arg == "tuichu" ){
	                write(HIR"你选择了退出！"NOR);
                	write("如果决定了就输入“Y”或者“y”？(Yes/No)");
			this_object()->set_temp("quit",1);
			i = 10;
        		do_xuan();
			return;
		}
	}
	temp += opt1[i]+"： "+msg[i]+"\n"; 
        i++;
        do_xuan();
}       
void get_menpai( string arg)
{

        if(!arg || arg == "")
        {
		write("你还没有写，如果不想选就写“no”吧。");
                input_to("get_menpai");
                return;
        }else if(arg != "no"){
 		if(!check_menpai(arg))
	        {
	                input_to("get_menpai");
	                return;
	        }
		msg[i] = mpname;
	}else{
		write(ESC + "[1A" + ESC + "[256D" + HIG +opt1[i]+"，此项你未选择。\n"NOR);
		msg[i]="此项未选。";
	}
	this_object()->set(opt1[i],msg[i]);
        temp += opt1[i]+"： "+msg[i]+"\n"; 
        i++;
        do_xuan();
}       
int check_menpai(string mp)
{
	string *mpx;
	write(ESC + "[1A" + ESC + "[256D" + "现在检验你所填写门派数据的有效性：\n");
	mpx = keys(menpai);
	for (int j=0; j<sizeof(mpx); j++) {
		if (mp == mpx[j] || mp == menpai[mpx[j]])
		{
			if (mp == mpx[j]) mpname = menpai[mpx[j]];
			write(ESC + "[1A" + ESC + "[256D"+HIG"你所填写的"+mpname+"是『" + INTERMUD_MUD_CNAME + "』中的门派，符合条件。\n"NOR);
			return 1;
		}
	}
	write(ESC + "[1A" + ESC + "[256D"+HIR + mp + "不是有效门派名或代码！请重新选"+opt1[i]+"：\n"NOR);
	return 0;
}

int check_legal_id(string id)
{
    int len;
    len = strlen(id);
    
     if( (strlen(id) < 3) || (strlen(id) > 60 )  ) {
        write("\n请用ID格式（五绝请用"HIY"半角字符"NOR"“"HIR","NOR"”隔开）？");
        return 0;
    }
    return 1;
}
int check_id(string id, int x)
{
        object ob;
        string *mpx, mpl;
	if (x == 8 && cnt == 0) write(ESC + "[1A" + ESC + "[256D" + "现在检验你所选五绝各ID的有效性：\n");
	else if (x != 8) write(ESC + "[1A" + ESC + "[256D" + "现在检验"+ id + "的有效性：\n");
	if (!objectp(ob = find_player(id)))
	{
		ob = new(USER_OB);
	        ob->set("id", id);   
		if( !ob->restore() ) {
			if (x == 8)
	        		write(ESC + "[1A" + ESC + "[256D"+HIR+ "五人中"+ id + "未注册！"NOR"请重新选五绝：");
	        	else write(ESC + "[1A" + ESC + "[256D"+HIR+ id + "还未注册！"NOR"请重新选"+opt1[i]+"谁会赢：");
			destruct(ob);
	                return 0;
		}
	}
	name = ob->name()+"("+id+")，";
	if (x == 8){
		cnt++;
		if (cnt == 5)
			write(ESC + "[1A" + ESC + "[256D"+HIG"所有五绝ID较验完毕，全部符合条件。你选择的"+opt1[i]+"是：\n"NOR);
		wujue += ob->short(1) + "\n";
		if (!objectp(ob)) destruct(ob);
		return 1;
	}
	if (ob->query("age") > age[x] && ob->query("age") <= age[x+1] ){
		write(ESC + "[1A" + ESC + "[256D"+HIG"数据较验完毕，" + NOR + ob->short(1) + HIG + "符合"+opt1[i]+"的条件。\n"NOR);
		if (!objectp(ob)) destruct(ob);
		return 1;
	}else{
		write(ESC + "[1A" + ESC + "[256D" + HIR + name + "不符合条件！请重新选择"+opt1[i]+"谁会赢："NOR);
		if (!objectp(ob)) destruct(ob);
		return 0;
	}
}
	
void confirm_xuan(string yn)
{
        object ob=this_object();
        int n;
        if( yn[0]!='y' && yn[0]!='Y' ) 
        {
                write("那好好考虑一下吧。\n");
		temp = "";
                i=0;
                cnt=0;
                wujue = "";
                return;
        }
	if ( ob->query_temp("quit") ){
		write("那你再考虑一下吧。\n");
		temp = "";
                i=0;
                cnt=0;
                wujue = "";
 		return;
	}
	temp += "\n这张选票是你在"+ctime(time())[0..15]+"填写的。\n";
        ob->set("done_time",time());
        ob->set("long",temp);
        ob->set("done",1);
        ob->set_name(this_player()->query("name")+"的比武选票",({this_player()->query("id")+"'s piao", "piao"}) );
        write("你填完了这张选票。\n");
        return;         
}
