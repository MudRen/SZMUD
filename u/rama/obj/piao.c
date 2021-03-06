//xuanpiao.c
//create by rama@sz

inherit ITEM;

#include <ansi.h>

void get_id( string arg);
int check_legal_id(string id);
void confirm_xuan(string yn);
void get_menpai(string arg);

string *opt1 = ({ 
"25岁以下组",
"30岁以下组",
"35岁以下组",
"40岁以下组",
"45岁以下组",
"55岁以下组",
"65岁以下组",
"99岁以下组",
"五绝得主(不分名次,猜中既可)",
"天下第一门派",
});

string *msg=({"","","","","","","","","","",""});
string temp="";
int i=0;

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
                write("你选好了么？(Yes/No)\n");
                input_to( (:confirm_xuan :) );
                return 1;
        }

        write("你觉得"+opt1[i]+"谁会赢？\n");
        input_to( (: get_id :));
        return 1;
        
}

void get_id( string arg)
{
        
        arg = lower_case(arg);
        if( !check_legal_id(arg)) 
        {
                input_to("get_id");
                return;
        }
        msg[i]=arg;
        temp += opt1[i]+"： "+msg[i]+"\n"; 
        i=i+1;
        do_xuan();
}       


int check_legal_id(string id)
{
    int len;
    len = strlen(id);
    
     if( (strlen(id) < 3) || (strlen(id) > 60 )  ) {
        write("请用ID格式（五绝请用，隔开）？\n");
        return 0;
    }
/*    while(len--)
        if( id[len]<'a' || id[len]>'z' || id[len]!="," ) {
            write("请用ID格式（五绝请用，隔开）？\n");
            return 0;
        }
*/
    return 1;
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
                return;
        }
		temp += "\n这张选票是你在"+ctime(time())[0..15]+"填写的。\n";
        ob->set("done_time",time());
        ob->set("long",temp);
        ob->set("done",1);
        ob->set_name(this_player()->query("name")+"的比武选票",({this_player()->query("id")+"'s piao"}) );
        write("你填完了这张选票。\n");
        return;         
}



