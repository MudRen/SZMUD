//[xiaojl 1999/11/20 武林春秋]
//buwu 修改于 2001/10/7
//Modified by tracy 6/1/2002 for wizre
#define SOS_DIR       "/data/sos"
#define SOS_FILENAME  "sos"
#include <ansi.h>
inherit F_CLEAN_UP;
inherit F_SAVE;
mapping *notes;
string query_save_file()
{
        return SOS_DIR + SOS_FILENAME ;
}
void done_post(object me, mapping note, string text)
{
    int i; //line 20
    note["msg"] = text;
    i = sizeof(notes);
    for( ; i > 0; i-- ) 
        if( notes[i-1]["author"] == me->query("id") ) break;
    if( !pointerp(notes) || i > 0 )
        if(!sizeof(notes)) notes = ({ note });
        else {
            notes[i-1]["title"] = note["title"];
            notes[i-1]["author"] = note["author"];
            notes[i-1]["msg"] = note["msg"];
            notes[i-1]["time"] = note["time"];
            notes[i-1]["solve"] = "";
            notes[i-1]["wizre"] = "";     
      }
    else
        notes += ({ note });
    tell_object(me, CYN "求救信息输入成功，正在向神仙传达。谢谢你的合作。\n");
    tell_object(me, CYN "或许神仙正在处理其他玩家的问题，请稍微等待一下。\n");
    tell_object(me, CYN "你可以先找些事做。如果必要，神仙可能会来找你交谈。\n");
    tell_object(me, CYN "等一会儿，你可以用 sos read 来查看问题是否已被解决。\n" NOR);
    message("channel:sys",HIR"【SOS】："+me->query("name")+"发出求救信号。\n"NOR,users());
    save();
    return;
}
void list_bug(object me)
{
    int i;
    string str,s;
    if (sizeof(notes)<1) {
        write("没人发出 sos 求救信号。\n");
        return;
    } 
    s = sprintf("玩家已经发出的 sos 列表如下:\n"
                HIW"==------------------------------------------------------------------=="NOR"\n");
    for( i = 0; i<sizeof(notes); i++){
        str = sprintf("%d) %-50s %10s %s %s \n",
                           i+1, notes[i]["title"], notes[i]["solve"]==""?"No solved":"By "+notes[i]["solve"],
                                               notes[i]["wizre"]==""?"":HIM"回复"NOR,
                           ctime(notes[i]["time"])[0..9] );
        s = s + str;
    }
    me->start_more(s);                
}
void do_read(object me, int i) 
{
    string s,str;
    if( i > sizeof(notes) || i < 1) {
        write("无此编号!!\n");
        return;
    }
    s = sprintf("%d) %-50s %10s %s\n"
                HIW"________________________________________________________________________"NOR"\n"
              "%s",
               i, notes[i-1]["title"], notes[i-1]["solve"]==""?"No solved":"By "+notes[i-1]["solve"],
               ctime(notes[i-1]["time"])[0..9], notes[i-1]["msg"] );
       if (notes[i-1]["wizre"]!="" && notes[i-1]["solve"]!="") 
       {
 str = sprintf(HIW"________________________________________________________________________"NOR"\n"
                          "神仙""(%s)" "给予的 回复是:\n\n" "%s",
               notes[i-1]["solve"],notes[i-1]["wizre"] );
       s=s+str;
       }
    me->start_more(s);
}
int search_id(string id)
{
    int i;
    if( !(i = sizeof(notes)) ) return 0;
    for( ; i > 0; i-- ) 
        if( notes[i-1]["author"] == id ) break;
    return i;
}
int do_solve(object me, int i)
{
    if( i > sizeof(notes) || i < 1) {
        write("无此编号!!\n");
        return 0;
    } 
    if ( notes[i-1]["solve"]!="" ) {
        write(notes[i-1]["solve"]+"已经标志啦!\n");
        return 1;
    }
    notes[i-1]["solve"] = me->query("id");
    save();
    write("该 sos 信息已标志为解决。\n");
    return 1;
}
void do_wizre(object me, int i,string text)
{
    if( i > sizeof(notes) || i < 1) {
        write("无此编号!!\n");
        return;
    } 
    if ( notes[i-1]["wizre"]!="" ) {
        write(notes[i-1]["solve"]+"已经回复了!\n");
        return;
    }
      notes[i-1]["solve"] = me->query("id");
     notes[i-1]["wizre"] = text; 
     save();
     write("该sos信息标志了并回复!\n");
     return;
}
int main(object me, string arg)
{
    mapping note;
    object where;
    string s, str,arg1; //line 40
    int i,arg2;
//    if (file_size(SOS_DIR + SOS_FILENAME) == -1) {
  //      notes = ({ });
    //    save();
    //}
    restore();
    if (!arg) {
        if(!wiz_level(me)){
            tell_object(me, CYN "当你正津津有味地玩着"HIW"【神州】"NOR""CYN"，不幸的系统错误却降临在了你的身上。\n");
            tell_object(me, CYN "在你确认这是"HIR" 系统 BUG"NOR""CYN" ，而不是"NOR""HIG"非法要求神仙协助你进行游戏"NOR""CYN"后，\n");
            tell_object(me, CYN "你毫不犹豫地向神仙们发出紧急求救信号："HIR"ＳＯＳ！！！\n" NOR);
            where = environment(me);
            if (!where) 
                s=sprintf("%s(%s)求救",
                        (string)me->name(),
                        (string)me->query("id"));
            else
                s=sprintf("%s(%s)在%s(%s)求救",
                        (string)me->name(),
                        (string)me->query("id"),
                        (string)where->query("short"),
                        (string)file_name(where));
            note = allocate_mapping(6);
            note["title"] = s;
            note["author"] = me->query("id"); 
            note["time"] = time();
            note["solve"] = "";
            note["wizre"] = ""; 
            me->edit( (: done_post, me, note :) );
        }
        else {
            list_bug(me);
        }
        return 1;
    } 
    if( sscanf(arg, "%s %d", s, i) == 2 ) {
        if( !wiz_level(me) ) return notify_fail("格式不对，具体使用方法请参阅 help sos \n"); 
        if ( s != "solve" && s!= "wizre") return notify_fail("格式不对，具体使用方法请参阅 help sos \n");
              if (s=="solve")   do_solve( me, i );
             if(s=="wizre" )  
              {
                            if( i > sizeof(notes) || i < 1) {
                       write("无此编号!!\n");
                    return 1;
              }
                if ( notes[i-1]["wizre"]!="" ) {
                          write(notes[i-1]["solve"]+"已经回复了!\n");
                 }
                else 
                {
                  if( i > 0 ) { 
                         me->edit( (: do_wizre, me,i:) );
                             }
                }
        }
                               return 1;
       }
 if( sscanf(arg, "%s %s", s, arg1) == 2 ) {
        if( !wiz_level(me) ) return notify_fail("格式不对，具体使用方法请参阅 help sos \n");
         switch(s){
              case "solve": 
         if ( arg1 =="all" ) {
                         if( !(i = sizeof(notes)) ) return notify_fail("没人发出sos求救信号。\n");
                  for( ; i > 0; i-- ) 
               notes[i-1]["solve"] = me->query("id");
                  write("所有的 sos 信息已经标志为解决了。\n");
                  return 1;
                       }
                   break;
              case "wizre":
                         break;
              default: 
                   return notify_fail("格式不对，具体使用方法请参阅 help sos \n");
                   break;    
        }
                                i = search_id(arg1);
                if (s=="wizre")
                {
                         if (i > 0)
                        if ( notes[i-1]["wizre"]!="" ) {
                          write(notes[i-1]["solve"]+"已经回复了!\n");
                          return 1;
                         }
            
                      else 
                          {
                  if( i > 0 ) { 
                         me->edit( (: do_wizre, me,i:) );
                        return 1;
                             }
                         }
                 }
        if (s=="solve")
          {
            if( i > 0 ) { 
                        do_solve( me, i );
                       return 1;
           }
          }
     }
    if ( sscanf(arg, "%s", s) == 1 ) 
    switch(arg){
        case "read":       
            if( !(i = sizeof(notes)) )
                return notify_fail("还没有人做过 sos 呼叫！\n");
            else {
                i = search_id( me->query("id") );
                do_read(me,i);
            }
            break;
        case "list":
            if( !wiz_level(me) ) return notify_fail("格式不对，具体使用方法请参阅 help sos \n");
            list_bug(me);
            break;
        case "pack":
                    if( !wiz_level(me) ) return notify_fail("格式不对，具体使用方法请参阅 help sos \n");
            if( !(i = sizeof(notes)) ) return notify_fail("没人发出 sos 求救信号。\n"); 
                for( ; i > 0; i-- ) 
                if( "" != notes[i-1]["solve"] && notes[i-1]["time"] < time() - 172800 ) { 
                                 if (notes[i-1]["wizre"]=="")
                                 {
                    printf("%s的 sos 求救已被删除！\n", notes[i-1]["author"]);
                    if( sizeof(notes) == 1 ) notes = ({});
                    else if(i==1) notes = notes[1..sizeof(notes)-1];
                    else if( i == sizeof(notes) ) notes = notes[0..sizeof(notes)-2];
                    else notes = notes = notes[0..i-2] + notes[i..sizeof(notes)-1];       
                                 }
else if (notes[i-1]["wizre"]!="" && me->query("id")=="hap" || wizhood(me) == "(arch)" || wizhood(me) == "(admin)")
                                  {
                    printf("%s的 sos 求救已被删除！\n", notes[i-1]["author"]);
                    if( sizeof(notes) == 1 ) notes = ({});
                    else if(i==1) notes = notes[1..sizeof(notes)-1];
                    else if( i == sizeof(notes) ) notes = notes[0..sizeof(notes)-2];
                    else notes = notes = notes[0..i-2] + notes[i..sizeof(notes)-1];        
                    }                               
                            }
                              save();
                              break;   
        case "solve":
            if( !wiz_level(me) ) return notify_fail("格式不对，具体使用方法请参阅 help sos \n");
            return notify_fail("格式: sos solve <编号或玩家id>\n");
            break;
        default:
            if( !wiz_level(me) ) return notify_fail("格式不对，具体使用方法请参阅 help sos \n");
            if( sscanf(arg, "%d", i) == 1 )
                do_read( me, i );
            else if( sscanf( arg, "%s", str ) == 1 ) {
                i = search_id(str);
                if( i == 0 ) return notify_fail("无此玩家发出的 sos 信息！\n");
                do_read( me, i );
            }
    }
    else return notify_fail("格式不对，具体使用方法请参阅 help sos \n");
    return 1;
}
int help(object me)
{
        if (!wiz_level(me) )
        write(@HELP
指令格式 : 
           sos
           sos read
这个指令可以在系统出现 BUG 时向神仙求助。输入该命令后，系统将提
示你输入对 BUG 的报告。 玩家应该将 BUG 出现的情况和系统的提示尽
量详细地说明，以便神仙以最快的速度修改该 BUG 。每个玩家只能贴一
条 sos，新的 sos 将覆盖以前的输入。
为了提高神仙的效率，请在使用 sos 命令前，仔细阅读 help rules，
以避免发生不愉快的事。玩家可以用 sos read 阅读自己贴出的 sos。
HELP
    );
        else 
write(@HELP
指令格式 : 
           sos <号码或玩家id>
           sos list
           sos pack
           sos solve <号码或玩家id>
                   sos wizre <号码或玩家id>
这个指令可以辅助巫师处理玩家提出的 BUG 列表。sos list 都是将所有
的 BUG 信息进行列表。带参数的 sos 命令，根据参数的不同，将显示对
应号码或对应玩家的 BUG 的详细信息。sos solve 用来标志某个 BUG 已
经被解决了。sos pack 将删除所有已经标志为解决了的 BUG，sos wizre
用来回复玩家。
HELP
    );
    return 1;
}
