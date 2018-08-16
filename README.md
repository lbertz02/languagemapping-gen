Mapping generation for content in the langaguemapping repository.

Two plugins are provided that take work from the langaguemapping repository:
1. ngic-ie - takes the IE YANG mappings then generates the definitions and structures found in the gtpv2c_ie.h file

From the test directory
> pyang --plugindir ../ -f ngic-ie ts29274-ies-f40.yang

2. ngic-message - takes the Messages YANG mappings then generates the gtpv2.h file and message file stubs

From the test directory
> pyang --plugindir ../ -f ngic-message ts29274-messages-f40.yang 

Note(s):
- The error returned for not providing mandatory IEs in a message should not be EPERM.
- Adding a holder in each message to place IEs not in the format will help it becomer resilient as a parser and should be considered.
- More could be automated but it would be ideal if we can link in the langaguemapping the presence to length attributes.
- The langaguemapping support should include table/section descriptions to help the generated code descriptions.
