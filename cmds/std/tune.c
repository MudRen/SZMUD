                                              // Code of ShenZhou
// tune.c
//Piao修改于2002-02-22，增加tune on和 tune off 功能。
inherit F_CLEAN_UP;



int main(object me, string arg)
{

        string* wiztune = ({
                "gwiz",
                "sys",
                "alarm",
                "rumor",
                "chat",
                "sz",
                "menpai",
                "jiaoyi"
        });
        
        string* usrtune = ({
                "rumor",
                "chat",
                "sz",
                "menpai",
                "jiaoyi",
        });
        string *tuned_ch;

        tuned_ch = me->query("channels");
        if( !arg ) 
        {
                if( !pointerp(tuned_ch) || !sizeof(tuned_ch) )
                        write("你现在并没有收听任何频道。\n");
                else
                        write("你现在收听的频道：" + implode(tuned_ch, ", ") + "。\n");
                return 1;
        }

        if(arg=="on") 
        {
                if (!wizardp(me))
                {
                        me->set("channels",usrtune);
                        write("你现在把: " + implode(usrtune, ", ") + "频道都打开了。\n");
                        return 1;
                }
                else
                {
                        me->set("channels",wiztune);
                        write("你现在把: " + implode(wiztune, ", ") + "频道都打开了。\n");
                        return 1;
                }
        }
        
        if(arg=="off") 
        {
                        me->set("channels","");
                        write("你现在把所有的频道都关闭了。\n");
                        return 1;
        }



        if( pointerp(tuned_ch) && member_array(arg, tuned_ch)!=-1 ) {
                write("关闭 " + arg + " 频道。\n");
                tuned_ch -= ({ arg });
                me->set("channels", tuned_ch);
                return 1;
        } else {
                write("要打开某个频道只要用该频道说话即可。\n");
                return 1;
        }
}

int help(object me)
{
        write(@HELP
指令格式：tune [<频道名称>]

这个指令让你选择是否要收听某一频道的讯息，如果没有指定频道名称，就会列出
你目前收听中的频道，如果指定了频道，原来收听中的就会关掉，反之打开。

如果你对一个没有收听中的频道讲话，会自动将它打开。
要对一个频道讲话，只要用：

<频道名称> <讯息> ....

例子：
  chat hello everyone!
  
你可以用 help channels 查询目前有哪些频道可以收听。

使用 tune on 命令可打开所有的频道，使用 tune off 命令可关闭所有的频道。

HELP
        );
        return 1;
}

