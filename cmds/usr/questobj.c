
int main(object me,string arg)
{
	mixed output;
	string ow,na;
	if(!arg||arg=="")
		return notify_fail("你想打听什么物品的消息？\n");
	if(me->is_busy()) return notify_fail("慢慢来，总得让人喘口气吧？\n");
	if(sscanf(arg,"%s的%s",ow,na)!=2) 
		return notify_fail("没有听说过这样东西。\n");
	output=TASK_D->query_location(arg);
	if(intp(output)&&output<0)
		return notify_fail("没有更多有关"+arg+"的消息。\n");
	if(stringp(output))
	{
		write(output);
		me->start_busy(1);
		return 1;
	}
	return 0;
}
int help(object me)
{
        write(@HELP
	questobj + 传书名单所列的中文全名。
HELP
    );
    return 1;
}
